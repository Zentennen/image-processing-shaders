// main.hpp

#pragma warning(push)
#pragma warning(disable: 4127)
#pragma warning(disable: 4201)
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#pragma warning(pop)

#include <avocado.hpp>
#include <avocado_render.hpp>

namespace avocado {
   struct renderapp final : application {
      renderapp();

      virtual bool on_init();
      virtual void on_exit();
      virtual bool on_tick(const time &deltatime);
      virtual void on_draw();

      glm::vec2 imageResolution;
      renderer renderer_;

      shader_program grey_shader;
      shader_program blur_shader;
      glm::mat3 blur_kernel;
      shader_program edge_shader;
      glm::mat3 edgeVKernel;
      glm::mat3 edgeHKernel;
      shader_program clear_shader;
      shader_program* shader;

      vertex_buffer buffer_;
      vertex_layout layout_;
      texture texture_;
      texture texture2_;
      sampler_state sampler_;
   };
} // !avocado
