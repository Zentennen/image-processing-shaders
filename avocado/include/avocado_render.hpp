// avocado_render.hpp

#ifndef AVOCADO_RENDER_HPP_INCLUDED
#define AVOCADO_RENDER_HPP_INCLUDED

#include <avocado.hpp>

namespace avocado {
   enum uniform_type {
      UNIFORM_TYPE_FLOAT,
      UNIFORM_TYPE_VEC2,
      UNIFORM_TYPE_VEC3,
      UNIFORM_TYPE_VEC4,
      UNIFORM_TYPE_INT,
      UNIFORM_TYPE_BOOL,
      UNIFORM_TYPE_SAMPLER,
      UNIFORM_TYPE_MATRIX,
      UNIFORM_TYPE_MAT3
   };

   enum texture_format {
      TEXTURE_FORMAT_RGB8,
      TEXTURE_FORMAT_RGBA8,
      TEXTURE_FORMAT_COUNT,
      TEXTURE_FORMAT_UNKNOWN,
   };

   enum cubemap_face {
      CUBEMAP_FACE_POSITIVE_X,
      CUBEMAP_FACE_NEGATIVE_X,
      CUBEMAP_FACE_POSITIVE_Y,
      CUBEMAP_FACE_NEGATIVE_Y,
      CUBEMAP_FACE_POSITIVE_Z,
      CUBEMAP_FACE_NEGATIVE_Z,
      CUBEMAP_FACE_COUNT,
   };

   enum sampler_filter_mode {
      SAMPLER_FILTER_MODE_NEAREST,
      SAMPLER_FILTER_MODE_LINEAR,
      SAMPLER_FILTER_MODE_NEAREST_MIP_NEAREST,
      SAMPLER_FILTER_MODE_NEAREST_MIP_LINEAR,
      SAMPLER_FILTER_MODE_LINEAR_MIP_NEAREST,
      SAMPLER_FILTER_MODE_LINEAR_MIP_LINEAR,
   };

   enum sampler_address_mode {
      SAMPLER_ADDRESS_MODE_CLAMP,
      SAMPLER_ADDRESS_MODE_WRAP,
      SAMPLER_ADDRESS_MODE_MIRROR,
   };

   enum buffer_access_mode {
      BUFFER_ACCESS_MODE_STATIC,
      BUFFER_ACCESS_MODE_DYNAMIC,
   };

   enum blend_equation {
      BLEND_EQUATION_ADD,
      BLEND_EQUATION_SUBTRACT,
      BLEND_EQUATION_REVERSE_SUBTRACT,
      BLEND_EQUATION_MIN,
      BLEND_EQUATION_MAX,
   };

   enum blend_factor {
      BLEND_FACTOR_ZERO,
      BLEND_FACTOR_ONE,
      BLEND_FACTOR_SRC_COLOR,
      BLEND_FACTOR_ONE_MINUS_SRC_COLOR,
      BLEND_FACTOR_DST_COLOR,
      BLEND_FACTOR_ONE_MINUS_DST_COLOR,
      BLEND_FACTOR_SRC_ALPHA,
      BLEND_FACTOR_ONE_MINUS_SRC_ALPHA,
      BLEND_FACTOR_DST_ALPHA,
      BLEND_FACTOR_ONE_MINUS_DST_ALPHA,
      BLEND_FACTOR_CONSTANT_COLOR,
      BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR,
      BLEND_FACTOR_CONSTANT_ALPHA,
      BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA,
      BLEND_FACTOR_SRC_ALPHA_SATURATE,
   };

   enum compare_func {
      COMPARE_FUNC_NEVER,
      COMPARE_FUNC_LESS,
      COMPARE_FUNC_EQUAL,
      COMPARE_FUNC_LESS_EQUAL,
      COMPARE_FUNC_GREATER,
      COMPARE_FUNC_NOT_EQUAL,
      COMPARE_FUNC_GREATER_EQUAL,
      COMPARE_FUNC_ALWAYS,
   };

   enum stencil_op {
      STENCIL_OP_KEEP,
      STENCIL_OP_ZERO,
      STENCIL_OP_REPLACE,
      STENCIL_OP_INCR,
      STENCIL_OP_INCR_WRAP,
      STENCIL_OP_DECR,
      STENCIL_OP_DECR_WRAP,
      STENCIL_OP_INVERT,
   };

   enum cull_mode {
      CULL_MODE_NONE,
      CULL_MODE_BACK,
      CULL_MODE_FRONT,
      CULL_MODE_BOTH,
   };

   enum front_face {
      FRONT_FACE_CCW,
      FRONT_FACE_CW,
   };

   enum polygon_mode {
      POLYGON_MODE_FILL,
      POLYGON_MODE_WIREFRAME,
   };

   enum primitive_topology {
      PRIMITIVE_TOPOLOGY_POINT_LIST,
      PRIMITIVE_TOPOLOGY_LINE_LIST,
      PRIMITIVE_TOPOLOGY_TRIANGLE_LIST,
   };

   enum index_type {
      INDEX_TYPE_UNSIGNED_BYTE,
      INDEX_TYPE_UNSIGNED_SHORT,
      INDEX_TYPE_UNSIGNED_INT,
   };

   enum framebuffer_format {
      FRAMEBUFFER_FORMAT_NONE,
      FRAMEBUFFER_FORMAT_RGB8,
      FRAMEBUFFER_FORMAT_RGBA8,
      FRAMEBUFFER_FORMAT_D32,
      FRAMEBUFFER_FORMAT_COUNT,
      FRAMEBUFFER_FORMAT_INVALID,
   };

   // note: resources
   struct shader_program { 
      shader_program();

      bool is_valid() const;
      bool create(const char *vertex_shader_source,
                  const char *fragment_shader_source);
      void destroy();

      uint32 id_; 
   };

   struct texture { 
      static texture_format from_bitmap_format(const bitmap::format format);

      texture();

      bool is_valid() const;
      bool create(const texture_format format,
                  const int32 width,
                  const int32 height,
                  const void *data);
      bool create(const texture_format format,
                  const int32 width,
                  const int32 height,
                  const int32 count,
                  const void **data);
      void update(const texture_format format,
                  const int32 width,
                  const int32 height,
                  const void *data);
      void destroy();

      uint32 id_; 
   };

   struct cubemap {
      cubemap();

      bool is_valid() const;
      bool create(const texture_format format,
                  const int32 width,
                  const int32 height,
                  const void *data[6]);
      void destroy();

      uint32 id_;
   };

   struct vertex_buffer {
      vertex_buffer();

      bool is_valid() const;
      bool create(const buffer_access_mode access,
                  const int32 size,
                  const void *data);
      void update(const int32 size,
                  const void *data);
      void destroy();

      uint32 id_;
   };

   struct index_buffer {
      index_buffer();

      bool is_valid() const;
      bool create(const int32 size,
                  const void *data);
      void destroy();

      uint32 id_;
   };

   struct sampler_state {
      sampler_state();

      bool is_valid() const;
      bool create(const sampler_filter_mode filter,
                  const sampler_address_mode addr_u,
                  const sampler_address_mode addr_v,
                  const sampler_address_mode addr_w = SAMPLER_ADDRESS_MODE_CLAMP);
      void destroy();

      uint32 id_;
   };

   struct framebuffer {
      static constexpr int32 ATTACHMENT_LIMIT = 4;

      framebuffer();

      bool is_valid() const;
      bool create(const int32 width,
                  const int32 height,
                  const int32 color_attachment_format_count,
                  const framebuffer_format *color_attachment_formats,
                  const bool has_depth_attachment = false,
                  const framebuffer_format depth_attachment_format = FRAMEBUFFER_FORMAT_NONE);
      void destroy();

      texture color_attachment_as_texture(const int32 index) const;

      uint32 id_;
      int32 width_;
      int32 height_;
      uint32 depth_attachment_;
      uint32 color_attachments_[ATTACHMENT_LIMIT];
   };

   struct vertex_layout
   {
      enum attribute_format {
         ATTRIBUTE_FORMAT_FLOAT,
         ATTRIBUTE_FORMAT_BYTE,
      };

      struct attribute
      {
         int32 index_;
         attribute_format format_;
         int32 count_;
         int32 offset_;
         bool normalized_;
      };

      vertex_layout();

      void add_attribute(const int32 index,
                         attribute_format format,
                         const int32 count,
                         const bool normalized);

      int32 stride_;
      int32 attribute_count_;
      attribute attributes_[8];
   };

   struct renderer {
      renderer();
      ~renderer();

      bool initialize();
      void shutdown();

      void clear(const float red, 
                 const float green, 
                 const float blue, 
                 const float alpha = 1.0f,
                 const float depth = 1.0f);
      void set_viewport(const int32 x, 
                        const int32 y,
                        const int32 width, 
                        const int32 height);
      void set_framebuffer(framebuffer &handle);
      void reset_framebuffer();
      void set_shader_program(shader_program &handle);
      void set_shader_uniform(shader_program &handle,
                              const uniform_type type,
                              const char *name, 
                              const int32 count, 
                              const void *value);
      void set_index_buffer(index_buffer &handle);
      void set_vertex_buffer(vertex_buffer &handle);
      void set_vertex_layout(vertex_layout &layout);
      void set_texture(const texture &handle, 
                       const int32 unit = 0);
      void set_cubemap(const cubemap &handle,
                       const int32 unit = 0);
      void set_sampler_state(sampler_state &handle, 
                             const int32 unit = 0);
      void set_blend_state(const bool enabled,
                           const blend_equation eq_rgb = BLEND_EQUATION_ADD,
                           const blend_factor src_rgb = BLEND_FACTOR_SRC_ALPHA,
                           const blend_factor dst_rgb = BLEND_FACTOR_ONE_MINUS_SRC_ALPHA,
                           const blend_equation eq_alpha = BLEND_EQUATION_ADD,
                           const blend_factor src_alpha = BLEND_FACTOR_ONE,
                           const blend_factor dst_alpha = BLEND_FACTOR_ONE);
      void set_depth_state(const bool testing,
                           const bool write,
                           const float range_near = -1.0f,
                           const float range_far = 1.0f,
                           const compare_func func = COMPARE_FUNC_LESS);
      void set_rasterizer_state(const cull_mode cull_mode = CULL_MODE_NONE,
                                const front_face front_face = FRONT_FACE_CCW,
                                const polygon_mode polygon = POLYGON_MODE_FILL);
      void draw(const primitive_topology topology,
                const int32 start_index,
                const int32 primitive_count);
      void draw_indexed(const primitive_topology topology,
                        const index_type type,
                        const int32 start_index,
                        const int32 primitive_count);
   };
} // !avocado

#endif // !AVOCADO_RENDER_HPP_INCLUDED
