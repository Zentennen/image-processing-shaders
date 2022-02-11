// avocado_winmain.cc

#include "avocado.hpp"
#include "avocado_opengl.h"

#define GL_FUNC(ret, name, ...) type_##name *name; 
OPENGL_BASE_FUNCTIONS;
OPENGL_CORE_FUNCTIONS;
OPENGL_DEBUG_OUTPUT_ARB_FUNCTIONS;
#undef GL_FUNC

#include <stdarg.h>
#include <stdlib.h>

#define WIN32_LEAN_AND_MEAN 1
#include <Windows.h>
#include <windowsx.h>
#include <ShellScalingApi.h>
#pragma comment(lib, "shcore.lib")

struct opengl_info {
   const char *vendor_;
   const char *renderer_;
   const char *version_;
};

struct opengl_version {
   int major_;
   int minor_;
};

struct opengl_capability {
   int max_texture_size_;
   int max_viewport_dims_;
   int max_3d_texture_size_;
   int max_elements_vertices_;
   int max_elements_indices_;
   int max_cube_map_texture_size_;
   int max_texture_lod_bias_;
   int max_draw_buffers_;
   int max_vertex_attribs_;
   int max_texture_image_units_;
   int max_fragment_uniform_components_;
   int max_vertex_uniform_components_;
   int max_varying_floats_;
   int max_vertex_texture_image_units_;
   int max_combined_texture_image_units_;
   int max_array_texture_layers_;
   int max_renderbuffer_size_;
   int max_color_attachments_;
   int max_texture_buffer_size_;
   int max_rectangle_texture_size_;
   int max_vertex_uniform_blocks_;
   int max_fragment_uniform_blocks_;
   int max_combined_uniform_blocks_;
   int max_uniform_buffer_bindings_;
   int max_uniform_block_size_;
   int max_combined_vertex_uniform_components_;
   int max_combined_fragment_uniform_components_;
   int max_color_texture_samples_;
   int max_depth_texture_samples_;
   int uniform_buffer_offset_alignment_;
};

#define WGL_DRAW_TO_WINDOW_ARB                     0x2001
#define WGL_ACCELERATION_ARB                       0x2003
#define WGL_SUPPORT_OPENGL_ARB                     0x2010
#define WGL_DOUBLE_BUFFER_ARB                      0x2011
#define WGL_PIXEL_TYPE_ARB                         0x2013
#define WGL_COLOR_BITS_ARB                         0x2014
#define WGL_DEPTH_BITS_ARB                         0x2022
#define WGL_STENCIL_BITS_ARB                       0x2023
#define WGL_FULL_ACCELERATION_ARB                  0x2027
#define WGL_TYPE_RGBA_ARB                          0x202B

#define WGL_CONTEXT_MAJOR_VERSION_ARB              0x2091
#define WGL_CONTEXT_MINOR_VERSION_ARB              0x2092
#define WGL_CONTEXT_LAYER_PLANE_ARB                0x2093
#define WGL_CONTEXT_FLAGS_ARB                      0x2094
#define WGL_CONTEXT_PROFILE_MASK_ARB               0x9126
#define WGL_CONTEXT_DEBUG_BIT_ARB                  0x0001
#define WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB     0x0002
#define WGL_CONTEXT_CORE_PROFILE_BIT_ARB           0x00000001
#define WGL_CONTEXT_COMPATIBILITY_PROFILE_BIT_ARB  0x00000002

typedef PROC(WINAPI type_wglGetProcAddress)(LPCSTR Arg1);
typedef BOOL(WINAPI type_wglMakeCurrent)(HDC hdc, HGLRC hrc);
typedef HGLRC(WINAPI type_wglCreateContext)(HDC hdc);
typedef BOOL(WINAPI type_wglDeleteContext)(HGLRC hrc);

typedef const char *(WINAPI type_wglGetExtensionsStringARB)(HDC hdc);
typedef BOOL(WINAPI type_wglChoosePixelFormatARB)(HDC hdc, const int *piAttribIList, const FLOAT *pfAttribFList,
                                                  UINT nMaxFormats, int *piFormats, UINT *nNumFormats);
typedef HGLRC(WINAPI type_wglCreateContextAttribsARB)(HDC hDC, HGLRC hShareContext, const int *attribList);
typedef BOOL(WINAPI type_wglSwapIntervalEXT)(int interval);

struct opengl_context {
   bool valid_;
   HMODULE dll_;
   HGLRC context_;
   opengl_info info_;
   opengl_version current_version_;
   opengl_version max_version_;
   opengl_capability capability_;
   type_wglGetProcAddress *wglGetProcAddress;
   type_wglMakeCurrent *wglMakeCurrent;
   type_wglCreateContext *wglCreateContext;
   type_wglDeleteContext *wglDeleteContext;
   type_wglGetExtensionsStringARB *wglGetExtensionsStringARB;
   type_wglChoosePixelFormatARB *wglChoosePixelFormatARB;
   type_wglCreateContextAttribsARB *wglCreateContextAttribsARB;
   type_wglSwapIntervalEXT *wglSwapIntervalEXT;
};

static void
opengl_debug_callback(GLenum source,
                      GLenum type,
                      GLuint id,
                      GLenum severity,
                      GLsizei length,
                      const GLchar *message,
                      const void *userParam)
{
   const char *source_str = "unknown";
   switch (source) {
      case GL_DEBUG_SOURCE_API_ARB:
      {
         source_str = "api";
      } break;
      case GL_DEBUG_SOURCE_WINDOW_SYSTEM_ARB:
      {
         source_str = "window_system";
      } break;
      case GL_DEBUG_SOURCE_SHADER_COMPILER_ARB:
      {
         source_str = "shader_compiler";
      } break;
      case GL_DEBUG_SOURCE_THIRD_PARTY_ARB:
      {
         source_str = "third_party";
      } break;
      case GL_DEBUG_SOURCE_APPLICATION_ARB:
      {
         source_str = "application";
      } break;
      case GL_DEBUG_SOURCE_OTHER_ARB:
      {
         source_str = "other";
      } break;
   }

   const char *type_str = "unknown";
   switch (type) {
      case GL_DEBUG_TYPE_ERROR_ARB:
      {
         type_str = "error";
      } break;
      case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR_ARB:
      {
         type_str = "depricated_behaviour";
      } break;
      case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR_ARB:
      {
         type_str = "undefined_behaviour";
      } break;
      case GL_DEBUG_TYPE_PORTABILITY_ARB:
      {
         type_str = "portability";
      } break;
      case GL_DEBUG_TYPE_PERFORMANCE_ARB:
      {
         type_str = "performance";
      } break;
      case GL_DEBUG_TYPE_OTHER_ARB:
      {
         type_str = "other";
      } break;
   }

   const char *severity_str = "unknown";
   switch (severity) {
      case GL_DEBUG_SEVERITY_HIGH_ARB:
      {
         severity_str = "high";
      } break;
      case GL_DEBUG_SEVERITY_MEDIUM_ARB:
      {
         severity_str = "medium";
      } break;
      case GL_DEBUG_SEVERITY_LOW_ARB:
      {
         severity_str = "low";
      } break;
   }

   (void)id;
   (void)length;
   (void)userParam;
   
   avocado::debug::error_box("OpenGL-Error!", 
                             "src='%s' type='%s' level='%s'\n\n%s",
                             source_str,
                             type_str,
                             severity_str,
                             message);
}

static bool
win32_opengl_load(opengl_context &gl)
{
   if (gl.valid_) {
      return true;
   }

   gl = {};
   HMODULE opengl_dll = LoadLibraryA("OpenGL32.dll");
   if (!opengl_dll) {
      return false;
   }

   // note: windows context base functions
   gl.dll_ = opengl_dll;
   gl.wglGetProcAddress = (type_wglGetProcAddress *)GetProcAddress(opengl_dll, "wglGetProcAddress");
   gl.wglMakeCurrent    = (type_wglMakeCurrent *)GetProcAddress(opengl_dll, "wglMakeCurrent");
   gl.wglCreateContext  = (type_wglCreateContext *)GetProcAddress(opengl_dll, "wglCreateContext");
   gl.wglDeleteContext  = (type_wglDeleteContext *)GetProcAddress(opengl_dll, "wglDeleteContext");

   // note: dummy window and context
   HWND dummy_window = CreateWindowA("STATIC",
                                     NULL, WS_POPUP | WS_DISABLED,
                                     CW_USEDEFAULT, CW_USEDEFAULT,
                                     CW_USEDEFAULT, CW_USEDEFAULT,
                                     NULL,
                                     NULL,
                                     GetModuleHandleA(NULL),
                                     NULL);

   PIXELFORMATDESCRIPTOR pfd = {};
   pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
   pfd.nVersion = 1;
   pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
   pfd.iPixelType = PFD_TYPE_RGBA;
   pfd.cColorBits = 32;
   pfd.cDepthBits = 24;
   pfd.cStencilBits = 8;
   pfd.iLayerType = PFD_MAIN_PLANE;

   HDC dummy_device = GetDC(dummy_window);
   int pixel_format_index = ChoosePixelFormat(dummy_device, &pfd);
   DescribePixelFormat(dummy_device, pixel_format_index, sizeof(PIXELFORMATDESCRIPTOR), &pfd);
   int pixel_format = SetPixelFormat(dummy_device, pixel_format_index, &pfd);
   HGLRC dummy_context = gl.wglCreateContext(dummy_device);
   gl.wglMakeCurrent(dummy_device, dummy_context);

   // note: load windows context extensions
   gl.wglGetExtensionsStringARB  = (type_wglGetExtensionsStringARB *)gl.wglGetProcAddress("wglGetExtensionsStringARB");
   gl.wglChoosePixelFormatARB    = (type_wglChoosePixelFormatARB *)gl.wglGetProcAddress("wglChoosePixelFormatARB");
   gl.wglCreateContextAttribsARB = (type_wglCreateContextAttribsARB *)gl.wglGetProcAddress("wglCreateContextAttribsARB");
   gl.wglSwapIntervalEXT         = (type_wglSwapIntervalEXT *)gl.wglGetProcAddress("wglSwapIntervalEXT");

   // note: load base opengl functions
#define GL_FUNC(ret, name, ...) name = (type_##name *)GetProcAddress(opengl_dll, #name);
   OPENGL_BASE_FUNCTIONS;
#undef GL_FUNC

   // note: load all core opengl functions
#define GL_FUNC(ret, name, ...) name = (type_##name *)gl.wglGetProcAddress(#name); 
   OPENGL_CORE_FUNCTIONS;
#undef GL_FUNC

   // note: load all optional opengl functions
   GL_ARB_debug_output_available = true;
#define GL_FUNC(ret, name, ...) \
   name = (type_##name *)gl.wglGetProcAddress(#name); \
   if (!name) { GL_ARB_debug_output_available = 1; }

   OPENGL_DEBUG_OUTPUT_ARB_FUNCTIONS;
#undef GL_FUNC

   // note: if we have proper debugging, set callback
   if (GL_ARB_debug_output_available) {
      glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS_ARB);
      glDebugMessageCallbackARB(opengl_debug_callback, NULL);
   }

   // note: query info
   opengl_info info = {};
   info.vendor_ = reinterpret_cast<const char *>(glGetString(GL_VENDOR));
   info.renderer_ = reinterpret_cast<const char*>(glGetString(GL_RENDERER));
   info.version_ = reinterpret_cast<const char *>(glGetString(GL_VERSION));
   gl.info_ = info;

   // note: query available version
   opengl_version version = {};
   glGetIntegerv(GL_MAJOR_VERSION, &version.major_);
   glGetIntegerv(GL_MINOR_VERSION, &version.minor_);
   gl.max_version_ = version;
   gl.current_version_ = { 3, 3 };

   // note: query capabilities
   opengl_capability caps = {};
   glGetIntegerv(GL_MAX_TEXTURE_SIZE, &caps.max_texture_size_);
   glGetIntegerv(GL_MAX_VIEWPORT_DIMS, &caps.max_viewport_dims_);
   glGetIntegerv(GL_MAX_3D_TEXTURE_SIZE, &caps.max_3d_texture_size_);
   glGetIntegerv(GL_MAX_ELEMENTS_VERTICES, &caps.max_elements_vertices_);
   glGetIntegerv(GL_MAX_ELEMENTS_INDICES, &caps.max_elements_indices_);
   glGetIntegerv(GL_MAX_CUBE_MAP_TEXTURE_SIZE, &caps.max_cube_map_texture_size_);
   glGetIntegerv(GL_MAX_TEXTURE_LOD_BIAS, &caps.max_texture_lod_bias_);
   glGetIntegerv(GL_MAX_DRAW_BUFFERS, &caps.max_draw_buffers_);
   glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &caps.max_vertex_attribs_);
   glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &caps.max_texture_image_units_);
   glGetIntegerv(GL_MAX_FRAGMENT_UNIFORM_COMPONENTS, &caps.max_fragment_uniform_components_);
   glGetIntegerv(GL_MAX_VERTEX_UNIFORM_COMPONENTS, &caps.max_vertex_uniform_components_);
   glGetIntegerv(GL_MAX_VARYING_FLOATS, &caps.max_varying_floats_);
   glGetIntegerv(GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS, &caps.max_vertex_texture_image_units_);
   glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &caps.max_combined_texture_image_units_);
   glGetIntegerv(GL_MAX_ARRAY_TEXTURE_LAYERS, &caps.max_array_texture_layers_);
   glGetIntegerv(GL_MAX_RENDERBUFFER_SIZE, &caps.max_renderbuffer_size_);
   glGetIntegerv(GL_MAX_COLOR_ATTACHMENTS, &caps.max_color_attachments_);
   glGetIntegerv(GL_MAX_TEXTURE_BUFFER_SIZE, &caps.max_texture_buffer_size_);
   glGetIntegerv(GL_MAX_RECTANGLE_TEXTURE_SIZE, &caps.max_rectangle_texture_size_);
   glGetIntegerv(GL_MAX_VERTEX_UNIFORM_BLOCKS, &caps.max_vertex_uniform_blocks_);
   glGetIntegerv(GL_MAX_FRAGMENT_UNIFORM_BLOCKS, &caps.max_fragment_uniform_blocks_);
   glGetIntegerv(GL_MAX_COMBINED_UNIFORM_BLOCKS, &caps.max_combined_uniform_blocks_);
   glGetIntegerv(GL_MAX_UNIFORM_BUFFER_BINDINGS, &caps.max_uniform_buffer_bindings_);
   glGetIntegerv(GL_MAX_UNIFORM_BLOCK_SIZE, &caps.max_uniform_block_size_);
   glGetIntegerv(GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS, &caps.max_combined_vertex_uniform_components_);
   glGetIntegerv(GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS, &caps.max_combined_fragment_uniform_components_);
   glGetIntegerv(GL_MAX_COLOR_TEXTURE_SAMPLES, &caps.max_color_texture_samples_);
   glGetIntegerv(GL_MAX_DEPTH_TEXTURE_SAMPLES, &caps.max_depth_texture_samples_);
   glGetIntegerv(GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT, &caps.uniform_buffer_offset_alignment_);
   gl.capability_ = caps;

   // note: destroy dummy window and context
   gl.wglMakeCurrent(NULL, NULL);
   gl.wglDeleteContext(dummy_context);
   DestroyWindow(dummy_window);

   // note: validate base and core functions
   gl.valid_ = false;
#define GL_FUNC(ret, name, ...) if (!name) { \
   MessageBoxA(NULL, "Could not load OpenGL function: '"#name"'", "ERROR!", MB_OK); \
   return false; \
   }

   OPENGL_BASE_FUNCTIONS;
   OPENGL_CORE_FUNCTIONS;
#undef GL_FUNC

   return gl.valid_ = true;
}

static void
win32_opengl_unload(opengl_context &gl)
{
   FreeLibrary(gl.dll_);
   gl = {};
}

static bool
win32_create_context(opengl_context &gl, HWND window_handle)
{
   if (!win32_opengl_load(gl)) {
      return false;
   }

   HDC device_context_handle = GetDC(window_handle);

   // note: create a core context
   PIXELFORMATDESCRIPTOR pfd = { 0 };
   pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
   pfd.nVersion = 1;
   pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
   pfd.iPixelType = PFD_TYPE_RGBA;
   pfd.cColorBits = 32;
   pfd.cDepthBits = 24;
   pfd.cStencilBits = 8;
   pfd.iLayerType = PFD_MAIN_PLANE;

   // note: select pixel format
   int pixel_format_index = ChoosePixelFormat(device_context_handle, &pfd);
   DescribePixelFormat(device_context_handle, pixel_format_index, sizeof(PIXELFORMATDESCRIPTOR), &pfd);

   const int pixel_format_attribs[] = {
      WGL_DRAW_TO_WINDOW_ARB, GL_TRUE          ,
      WGL_SUPPORT_OPENGL_ARB, GL_TRUE          ,
      WGL_DOUBLE_BUFFER_ARB , GL_TRUE          ,
      WGL_PIXEL_TYPE_ARB    , WGL_TYPE_RGBA_ARB,
      WGL_COLOR_BITS_ARB    , 32               ,
      WGL_DEPTH_BITS_ARB    , 24               ,
      WGL_STENCIL_BITS_ARB  , 8                ,
      0
   };
   UINT num_pixel_formats = 0;
   gl.wglChoosePixelFormatARB(device_context_handle,
                               pixel_format_attribs,
                               0,
                               1,
                               &pixel_format_index,
                               &num_pixel_formats);
   DescribePixelFormat(device_context_handle,
                       pixel_format_index,
                       sizeof(pfd),
                       &pfd);
   SetPixelFormat(device_context_handle,
                  pixel_format_index,
                  &pfd);

   const int context_attrib_list[] = {
      WGL_CONTEXT_MAJOR_VERSION_ARB, 3                               ,
      WGL_CONTEXT_MINOR_VERSION_ARB, 3                               ,
      WGL_CONTEXT_PROFILE_MASK_ARB , WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
#if defined(_DEBUG)
      WGL_CONTEXT_FLAGS_ARB        , WGL_CONTEXT_DEBUG_BIT_ARB       ,
#else
      WGL_CONTEXT_FLAGS_ARB        , 0                               ,
#endif
      0
   };
   HGLRC render_context_handle = gl.wglCreateContextAttribsARB(device_context_handle,
                                                               NULL,
                                                               context_attrib_list);
   if (gl.wglMakeCurrent(device_context_handle, render_context_handle) == FALSE) {
      return false;
   }

   gl.context_ = render_context_handle;

   return true;
}

static void
win32_destroy_context(opengl_context &gl)
{
   gl.wglMakeCurrent(NULL, NULL);
   gl.wglDeleteContext(gl.context_);
   gl.context_ = NULL;

   win32_opengl_unload(gl);
}

struct win32_input {
   struct {
      bool current_;
      bool previous_;
   } keys_[int(avocado::keyboard::key::count)]{};
   int x_;
   int y_;
   int wheel_;
   struct {
      bool current_;
      bool previous_;
   } buttons_[int(avocado::mouse::button::count)]{};
};

static void
win32_process_mouse(win32_input &input, avocado::mouse &mouse)
{
   mouse.position_.x_ = input.x_;
   mouse.position_.y_ = input.y_;
   for (int index = 0; index < int(avocado::mouse::button::count); index++) {
      mouse.buttons_[index].previous_ = input.buttons_[index].previous_;
      mouse.buttons_[index].current_  = input.buttons_[index].current_;
   }
}

static void 
win32_process_keyboard(win32_input &input, avocado::keyboard &keyboard)
{
   for (int index = 0; index < int(avocado::keyboard::key::count); index++) {
      keyboard.keys_[index].previous_ = input.keys_[index].previous_;
      keyboard.keys_[index].current_  = input.keys_[index].current_;
   }
}

static void
win32_process_input(win32_input &input)
{
   input.wheel_ = 0;
   for (int index = 0; index < int(avocado::mouse::button::count); index++) {
      input.buttons_[index].previous_ = input.buttons_[index].current_;
   }

   for (int index = 0; index < int(avocado::keyboard::key::count); index++) {
      input.keys_[index].previous_ = input.keys_[index].current_;
   }
}

struct win32_window {
   HWND handle_;
   HDC device_;
   win32_input input_;
};

static WPARAM
win32_convert_extended(WPARAM wParam, LPARAM lParam)
{
   WPARAM result = wParam;
   UINT scancode = (lParam & 0x00ff0000) >> 16;
   int  extended = (lParam & 0x01000000) != 0;

   switch (wParam) {
      case VK_SHIFT:
         result = MapVirtualKey(scancode, MAPVK_VSC_TO_VK_EX);
         break;
      case VK_CONTROL:
         result = extended ? VK_RCONTROL : VK_LCONTROL;
         break;
      case VK_MENU:
         result = extended ? VK_RMENU : VK_LMENU;
         break;
   }

   return result;
}

static avocado::keyboard::key
win32_convert_virtual(WPARAM wParam)
{
   switch (wParam) {
      case VK_BACK: return avocado::keyboard::key::back;
      case VK_TAB: return avocado::keyboard::key::tab;
      case VK_CLEAR: return avocado::keyboard::key::clear;
      case VK_RETURN: return avocado::keyboard::key::enter;
      case VK_SHIFT: return avocado::keyboard::key::shift;
      case VK_CONTROL: return avocado::keyboard::key::control;
      case VK_MENU: return avocado::keyboard::key::alt;
      case VK_PAUSE: return avocado::keyboard::key::pause;
      case VK_CAPITAL: return avocado::keyboard::key::capslock;
      case VK_ESCAPE: return avocado::keyboard::key::escape;
      case VK_SPACE: return avocado::keyboard::key::space;
      case VK_PRIOR: return avocado::keyboard::key::pageup;
      case VK_NEXT: return avocado::keyboard::key::pagedown;
      case VK_END: return avocado::keyboard::key::end;
      case VK_HOME: return avocado::keyboard::key::home;
      case VK_LEFT: return avocado::keyboard::key::left;
      case VK_UP: return avocado::keyboard::key::up;
      case VK_RIGHT: return avocado::keyboard::key::right;
      case VK_DOWN: return avocado::keyboard::key::down;
      case VK_PRINT: return avocado::keyboard::key::printscreen;
      case VK_INSERT: return avocado::keyboard::key::insert;
      case VK_DELETE: return avocado::keyboard::key::del;
      case '0': return avocado::keyboard::key::zero;
      case '1': return avocado::keyboard::key::one;
      case '2': return avocado::keyboard::key::two;
      case '3': return avocado::keyboard::key::three;
      case '4': return avocado::keyboard::key::four;
      case '5': return avocado::keyboard::key::five;
      case '6': return avocado::keyboard::key::six;
      case '7': return avocado::keyboard::key::seven;
      case '8': return avocado::keyboard::key::eight;
      case '9': return avocado::keyboard::key::nine;
      case 'A': return avocado::keyboard::key::a;
      case 'B': return avocado::keyboard::key::b;
      case 'C': return avocado::keyboard::key::c;
      case 'D': return avocado::keyboard::key::d;
      case 'E': return avocado::keyboard::key::e;
      case 'F': return avocado::keyboard::key::f;
      case 'G': return avocado::keyboard::key::g;
      case 'H': return avocado::keyboard::key::h;
      case 'I': return avocado::keyboard::key::i;
      case 'J': return avocado::keyboard::key::j;
      case 'K': return avocado::keyboard::key::k;
      case 'L': return avocado::keyboard::key::l;
      case 'M': return avocado::keyboard::key::m;
      case 'N': return avocado::keyboard::key::n;
      case 'O': return avocado::keyboard::key::o;
      case 'P': return avocado::keyboard::key::p;
      case 'Q': return avocado::keyboard::key::q;
      case 'R': return avocado::keyboard::key::r;
      case 'S': return avocado::keyboard::key::s;
      case 'T': return avocado::keyboard::key::t;
      case 'U': return avocado::keyboard::key::u;
      case 'V': return avocado::keyboard::key::v;
      case 'W': return avocado::keyboard::key::w;
      case 'X': return avocado::keyboard::key::x;
      case 'Y': return avocado::keyboard::key::y;
      case 'Z': return avocado::keyboard::key::z;
      case VK_NUMPAD0: return avocado::keyboard::key::keypad0;
      case VK_NUMPAD1: return avocado::keyboard::key::keypad1;
      case VK_NUMPAD2: return avocado::keyboard::key::keypad2;
      case VK_NUMPAD3: return avocado::keyboard::key::keypad3;
      case VK_NUMPAD4: return avocado::keyboard::key::keypad4;
      case VK_NUMPAD5: return avocado::keyboard::key::keypad5;
      case VK_NUMPAD6: return avocado::keyboard::key::keypad6;
      case VK_NUMPAD7: return avocado::keyboard::key::keypad7;
      case VK_NUMPAD8: return avocado::keyboard::key::keypad8;
      case VK_NUMPAD9: return avocado::keyboard::key::keypad9;
      case VK_MULTIPLY: return avocado::keyboard::key::keypadmultiply;
      case VK_ADD: return avocado::keyboard::key::keypadadd;
      case VK_SEPARATOR: return avocado::keyboard::key::keypadseparator;
      case VK_SUBTRACT: return avocado::keyboard::key::keypadsubtract;
      case VK_DECIMAL: return avocado::keyboard::key::keypaddecimal;
      case VK_DIVIDE: return avocado::keyboard::key::keypaddivide;
      case VK_F1: return avocado::keyboard::key::f1;
      case VK_F2: return avocado::keyboard::key::f2;
      case VK_F3: return avocado::keyboard::key::f3;
      case VK_F4: return avocado::keyboard::key::f4;
      case VK_F5: return avocado::keyboard::key::f5;
      case VK_F6: return avocado::keyboard::key::f6;
      case VK_F7: return avocado::keyboard::key::f7;
      case VK_F8: return avocado::keyboard::key::f8;
      case VK_F9: return avocado::keyboard::key::f9;
      case VK_F10: return avocado::keyboard::key::f10;
      case VK_F11: return avocado::keyboard::key::f11;
      case VK_F12: return avocado::keyboard::key::f12;
      case VK_NUMLOCK: return avocado::keyboard::key::numlock;
      case VK_SCROLL: return avocado::keyboard::key::scrolllock;
      case VK_LSHIFT: return avocado::keyboard::key::leftshift;
      case VK_RSHIFT: return avocado::keyboard::key::rightshift;
      case VK_LCONTROL: return avocado::keyboard::key::leftcontrol;
      case VK_RCONTROL: return avocado::keyboard::key::rightcontrol;
      case VK_LMENU: return avocado::keyboard::key::leftalt;
      case VK_RMENU: return avocado::keyboard::key::rightalt;
      case VK_OEM_1: return avocado::keyboard::key::oem1;
      case VK_OEM_PLUS: return avocado::keyboard::key::oemplus;
      case VK_OEM_COMMA: return avocado::keyboard::key::oemcomma;
      case VK_OEM_MINUS: return avocado::keyboard::key::oemminus;
      case VK_OEM_PERIOD: return avocado::keyboard::key::oemperiod;
      case VK_OEM_2: return avocado::keyboard::key::oem2;
      case VK_OEM_3: return avocado::keyboard::key::oem3;
      case VK_OEM_4: return avocado::keyboard::key::oem4;
      case VK_OEM_5: return avocado::keyboard::key::oem5;
      case VK_OEM_6: return avocado::keyboard::key::oem6;
      case VK_OEM_7: return avocado::keyboard::key::oem7;
      case VK_OEM_8: return avocado::keyboard::key::oem8;
      case VK_OEM_102: return avocado::keyboard::key::oem102;
   }

   return avocado::keyboard::key::none;
}

static LRESULT CALLBACK
win32_window_callback(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
   win32_window *window = (win32_window *)GetWindowLongPtrA(hwnd, GWLP_USERDATA);
   if (!window) {
      return DefWindowProcA(hwnd, message, wParam, lParam);
   }

   LRESULT result = 0;

   switch (message) {
      case WM_MOUSEMOVE:
      {
         window->input_.y_ = GET_Y_LPARAM(lParam);
         window->input_.x_ = GET_X_LPARAM(lParam);
      } break;
      case WM_MOUSEWHEEL:
      {
         window->input_.wheel_ = GET_WHEEL_DELTA_WPARAM(wParam) / WHEEL_DELTA;
      } break;
      case WM_LBUTTONDOWN:
      case WM_LBUTTONUP:
      {
         window->input_.buttons_[int(avocado::mouse::button::left)].current_ = (message == WM_LBUTTONDOWN) ? true : false;
      } break;
      case WM_RBUTTONDOWN:
      case WM_RBUTTONUP:
      {
         window->input_.buttons_[int(avocado::mouse::button::right)].current_ = (message == WM_RBUTTONDOWN) ? true : false;
      } break;
      case WM_MBUTTONDOWN:
      case WM_MBUTTONUP:
      {
         window->input_.buttons_[int(avocado::mouse::button::middle)].current_ = (message == WM_MBUTTONDOWN) ? true : false;
      } break;

      case WM_KEYDOWN:
      case WM_KEYUP:
      {
         wParam = win32_convert_extended(wParam, lParam);
         auto key = win32_convert_virtual(wParam);
         window->input_.keys_[int(key)].current_ = (message == WM_KEYDOWN) ? true : false;
      } break;

      case WM_CLOSE:
      {
         PostQuitMessage(0);
      } break;

      default:
      {
         result = DefWindowProcA(hwnd, message, wParam, lParam);
      } break;
   }

   return result;
}

static bool
win32_create_window(win32_window &window, 
                    const int width, 
                    const int height, 
                    const char *title, 
                    const bool borderless,
                    const bool center)
{
   SetProcessDpiAwareness(PROCESS_SYSTEM_DPI_AWARE);

   // note: register window class
   WNDCLASSA wc = { 0 };
   wc.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW;
   wc.lpfnWndProc = win32_window_callback;
   wc.hInstance = GetModuleHandle(NULL);
   wc.hCursor = LoadCursor(NULL, IDC_ARROW);
   wc.hbrBackground = CreateSolidBrush(0x00000000);
   wc.lpszClassName = "madnessWindowClassName";
   if (!RegisterClassA(&wc)) {
      return false;
   }

   // note: fix window size for style
   DWORD window_style = (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU);
   if (borderless) {
      window_style = WS_POPUP;
   }
   RECT window_rect = { 0 };
   window_rect.right = width;
   window_rect.bottom = height;
   if (!AdjustWindowRect(&window_rect, window_style, FALSE)) {
      return 0;
   }

   int window_x = CW_USEDEFAULT;
   int window_y = CW_USEDEFAULT;
   if (center) {
      window_x = (GetSystemMetrics(SM_CXSCREEN) - window_rect.right) / 2;
      window_y = (GetSystemMetrics(SM_CYSCREEN) - window_rect.bottom) / 2;
   }

   // note: create the actual window
   HWND window_handle = CreateWindowA(wc.lpszClassName,
                                      title,
                                      window_style,
                                      window_x,
                                      window_y,
                                      window_rect.right - window_rect.left,
                                      window_rect.bottom - window_rect.top,
                                      0, 0, wc.hInstance, 0);

   // note: set the window for input
   SetWindowLongPtrA(window_handle, GWLP_USERDATA, (LONG_PTR)&window);

   // note: show the window normally and invalidate
   ShowWindow(window_handle, SW_SHOWNORMAL);
   UpdateWindow(window_handle);

   window.handle_ = window_handle;
   window.device_ = GetDC(window_handle);

   return true;
}

static void
win32_destroy_window(win32_window &window)
{
   DestroyWindow(window.handle_);
   window.handle_ = NULL;
   window.device_ = NULL;
}

static bool
win32_process(win32_window &window)
{
   MSG msg = { 0 };
   while (PeekMessageA(&msg, NULL, 0, 0, PM_REMOVE)) {
      if (msg.message == WM_QUIT) {
         return false;
      }

      TranslateMessage(&msg);
      DispatchMessageA(&msg);
   }

   return true;
}

static void 
win32_present(win32_window &window)
{
   SwapBuffers(window.device_);
}

static int
win32_error_message(const char *title, const char *format, ...)
{
   char message[2048] = {};
   va_list vargs;
   va_start(vargs, format);
   vsprintf_s(message, format, vargs);
   va_end(vargs);
   MessageBoxA(NULL, message, title, MB_OK | MB_ICONERROR);
   return 0;
}

int WINAPI WinMain(HINSTANCE instance, HINSTANCE prev_instance, LPSTR command_line, int command_show)
{
   avocado::settings settings{ "avocado", 1280, 720, false };
   avocado::application *app = avocado::application::create(settings);
   if (!app) {
      return win32_error_message("ERROR!", "Could not create application!");
   }

   win32_window window = {};
   if (!win32_create_window(window, 
                            settings.width_, 
                            settings.height_, 
                            settings.title_.c_str(), 
                            settings.borderless_, 
                            settings.center_)) 
   {
      return win32_error_message("ERROR!", "Could not create window!");
   }

   opengl_context context = {};
   if (!win32_create_context(context, window.handle_)) {
      return win32_error_message("ERROR!", "Could not create opengl context!");
   }

   if (!app->on_init()) {
      return 0; //win32_error_message("ERROR!", "Could not initialze application!");
   }

   while (win32_process(window)) {
      win32_process_keyboard(window.input_, app->keyboard_);
      win32_process_mouse(window.input_, app->mouse_);
      win32_process_input(window.input_);
      if (!app->on_tick(avocado::time::deltatime())) {
         break;
      }
      app->on_draw();
      win32_present(window);
      Sleep(5); // note: save the forest yeah...
   }

   app->on_exit();
   delete app;

   win32_destroy_context(context);
   win32_destroy_window(window);

   return 0;
}
