// main.cc

#include "main.hpp"

namespace avocado {
   // note: application create implementation
   application *application::create(settings &settings)
   {
      settings.title_      = "renderapp";
      settings.width_      = 1280;
      settings.height_     = 720;
      settings.center_     = true;

      return new renderapp;
   }

   // note: renderapp class
   renderapp::renderapp() : shader(&clear_shader)
   {
       for (int i = 0; i < 3; i++) {
           for (int j = 0; j < 3; j++) {
               blur_kernel[i][j] = 1.0f / 9.0f;
           }
       }
       edgeHKernel =
       {
           -2, 0, 2,
           -2, 0, 2,
           -2, 0, 2
       };
       edgeVKernel =
       {
           2, 2, 2,
           0, 0, 0,
           -2, -2, -2
       };
   }

   bool renderapp::on_init()
   {
      if (!renderer_.initialize()) {
         return false;
      }

      string applyKernel;
      if (!file_system::read_file_content("assets/applyKernel.txt", applyKernel)) {
          return on_error("could not read kernel file content!");
      }

      // note: create shader program
      {
         string vertex_source;
         if (!file_system::read_file_content("assets/grey.vs.txt", vertex_source)) {
            return on_error("could not read vertex shader file content!");
         }

         string fragment_source;
         if (!file_system::read_file_content("assets/grey.fs.txt", fragment_source)) {
            return on_error("could not read fragment shader file content!");
         }

         if (!grey_shader.create(vertex_source.c_str(), fragment_source.c_str())) {
            return on_error("could not create shader program!");
         }
      }

      // note: create shader program
      {
          string vertex_source;
          if (!file_system::read_file_content("assets/blur.vs.txt", vertex_source)) {
              return on_error("could not read vertex shader file content!");
          }

          string fragment_source;
          if (!file_system::read_file_content("assets/blur.fs.txt", fragment_source)) {
              return on_error("could not read fragment shader file content!");
          }
          fragment_source = applyKernel + fragment_source;

          if (!blur_shader.create(vertex_source.c_str(), fragment_source.c_str())) {
              return on_error("could not create shader program!");
          }
      }

      // note: create shader program
      {
          string vertex_source;
          if (!file_system::read_file_content("assets/edge.vs.txt", vertex_source)) {
              return on_error("could not read vertex shader file content!");
          }

          string fragment_source;
          if (!file_system::read_file_content("assets/edge.fs.txt", fragment_source)) {
              return on_error("could not read fragment shader file content!");
          }
          fragment_source = applyKernel + fragment_source;
          

          if (!edge_shader.create(vertex_source.c_str(), fragment_source.c_str())) {
              return on_error("could not create shader program!");
          }
      }

      // note: create shader program
      {
          string vertex_source;
          if (!file_system::read_file_content("assets/clear.vs.txt", vertex_source)) {
              return on_error("could not read vertex shader file content!");
          }

          string fragment_source;
          if (!file_system::read_file_content("assets/clear.fs.txt", fragment_source)) {
              return on_error("could not read fragment shader file content!");
          }

          if (!clear_shader.create(vertex_source.c_str(), fragment_source.c_str())) {
              return on_error("could not create shader program!");
          }
      }

      // note: create vertices
      {
         struct {
            glm::vec2 position_;
            glm::vec2 texcoord_;
         } vertices[] =
         {
            { glm::vec2(-1.0f, 1.0f), glm::vec2(0.0f, 0.0f) },
            { glm::vec2(1.0f, 1.0f), glm::vec2(1.0f, 0.0f) },
            { glm::vec2(1.0f,-1.0f), glm::vec2(1.0f, 1.0f) },
            { glm::vec2(1.0f,-1.0f), glm::vec2(1.0f, 1.0f) },
            { glm::vec2(-1.0f,-1.0f), glm::vec2(0.0f, 1.0f) },
            { glm::vec2(-1.0f, 1.0f), glm::vec2(0.0f, 0.0f) },
         };

         if (!buffer_.create(BUFFER_ACCESS_MODE_STATIC, sizeof(vertices), vertices)) {
            return on_error("could not create vertex buffer!");
         }
      }

      // note: create vertex layout
      {
         layout_.add_attribute(0, vertex_layout::ATTRIBUTE_FORMAT_FLOAT, 2, false);
         layout_.add_attribute(1, vertex_layout::ATTRIBUTE_FORMAT_FLOAT, 2, false);
      }

      // note: create texture
      {
         bitmap image;
         if (!image.create("assets/image.jpg")) {
            return on_error("could not load image file!");
         }

         if (!texture_.create(texture::from_bitmap_format(image.pixel_format()),
                              image.width(),
                              image.height(),
                              image.data()))
         {
            return on_error("could not create texture!");
         }

         imageResolution = { image.width(), image.height() };

         image.destroy();
      }

      // note: create texture
      {
          bitmap image;
          if (!image.create("assets/grass.jpg")) {
              return on_error("could not load image file!");
          }

          if (!texture2_.create(texture::from_bitmap_format(image.pixel_format()),
              image.width(),
              image.height(),
              image.data()))
          {
              return on_error("could not create texture!");
          }

          image.destroy();
      }

      // note: create sampler state
      {
         if (!sampler_.create(SAMPLER_FILTER_MODE_LINEAR,
                              SAMPLER_ADDRESS_MODE_CLAMP,
                              SAMPLER_ADDRESS_MODE_CLAMP))
         {
            return on_error("could not create sampler state!");
         }
      }

      return true;
   }

   void renderapp::on_exit()
   {
   }

   bool renderapp::on_tick(const time &deltatime)
   {
      if (keyboard_.key_pressed(keyboard::key::escape)) {
         return false;
      }

      if (keyboard_.key_pressed(keyboard::key::c)) {
          shader = &clear_shader;
      }
      if (keyboard_.key_pressed(keyboard::key::b)) {
          shader = &blur_shader;
      }
      if (keyboard_.key_pressed(keyboard::key::e)) {
          shader = &edge_shader;
      }
      if (keyboard_.key_pressed(keyboard::key::g)) {
          shader = &grey_shader;
      }
      glm::mat3 a;
      a[1][2] = 5;
      return true;
   }

   void renderapp::on_draw()
   {
      renderer_.clear(0.1f, 0.15f, 0.2f, 1.0f);
      renderer_.set_sampler_state(sampler_);
      renderer_.set_vertex_buffer(buffer_);
      renderer_.set_vertex_layout(layout_);
      
      renderer_.set_shader_program(*shader);
      int32 texIndex0 = 0;
      int32 texIndex1 = 1;
      renderer_.set_shader_uniform(*shader, UNIFORM_TYPE_SAMPLER, "u_diffuse", 1, &texIndex1);
      renderer_.set_texture(texture_, 1);
      
      if (shader == &blur_shader) {
          renderer_.set_shader_uniform(blur_shader, UNIFORM_TYPE_VEC2, "u_resolution", 1, glm::value_ptr(imageResolution));
          renderer_.set_shader_uniform(blur_shader, UNIFORM_TYPE_MAT3, "u_kernel", 1, glm::value_ptr(blur_kernel));
      }
      if (shader == &edge_shader) {
          renderer_.set_shader_uniform(edge_shader, UNIFORM_TYPE_VEC2, "u_resolution", 1, glm::value_ptr(imageResolution));
          renderer_.set_shader_uniform(edge_shader, UNIFORM_TYPE_MAT3, "u_vkernel", 1, glm::value_ptr(edgeVKernel));
          renderer_.set_shader_uniform(edge_shader, UNIFORM_TYPE_MAT3, "u_hkernel", 1, glm::value_ptr(edgeHKernel));
      }
      renderer_.draw(PRIMITIVE_TOPOLOGY_TRIANGLE_LIST, 0, 6);
   }
} // !avocado
