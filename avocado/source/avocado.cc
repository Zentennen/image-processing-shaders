// avocado.cc

#include "avocado.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include <stdarg.h>
#include <stdlib.h>

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

namespace avocado {
   // static
   bool debug::message_box(const char *caption, const char *format, ...)
   {
      char message[2048] = {};
      va_list vargs;
      va_start(vargs, format);
      vsprintf_s(message, format, vargs);
      va_end(vargs);
      return MessageBoxA(NULL, message, caption, MB_OKCANCEL | MB_ICONINFORMATION) == IDOK;
   }

   bool debug::error_box(const char *caption, const char *format, ...)
   {
      char message[2048] = {};
      va_list vargs;
      va_start(vargs, format);
      vsprintf_s(message, format, vargs);
      va_end(vargs);
      return MessageBoxA(NULL, message, caption, MB_OKCANCEL | MB_ICONERROR) == IDOK;
   }

   point::point()
      : x_(0)
      , y_(0)
   {
   }

   point::point(const int32 x, const int32 y)
      : x_(x)
      , y_(y)
   {
   }

   point point::operator+(const point &rhs) const
   {
      return { x_ + rhs.x_, y_ + rhs.y_ };
   }

   point point::operator-(const point &rhs) const
   {
      return { x_ - rhs.x_, y_ - rhs.y_ };
   }

   bool point::operator==(const point &rhs) const
   {
      return x_ == rhs.x_ && y_ == rhs.y_;
   }

   bool point::operator!=(const point &rhs) const
   {
      return x_ != rhs.x_ || y_ != rhs.y_;
   }

   // static
   time time::deltatime()
   {
      static time previous;
      time current = time::now();
      time delta = current - previous;
      previous = current;
      return delta;
   }

   time time::now() {
      static LARGE_INTEGER start = {};
      static int64 factor = 0;
      if (!factor)
      {
         LARGE_INTEGER f = {};
         QueryPerformanceFrequency(&f);
         factor = f.QuadPart / 1000;
         QueryPerformanceCounter(&start);
      }

      LARGE_INTEGER now = {};
      QueryPerformanceCounter(&now);

      return time((now.QuadPart - start.QuadPart) / factor);
   }

   time::time()
      : ticks_(0)
   {
   }

   time::time(int64 ticks)
      : ticks_(ticks)
   {
   }

   time::time(const double seconds)
      : ticks_(static_cast<int64>(seconds * 1000000.0))
   {
   }

   time &time::operator+=(const time &rhs)
   {
      ticks_ += rhs.ticks_;
      return *this;
   }

   time &time::operator-=(const time &rhs)
   {
      ticks_ -= rhs.ticks_;
      return *this;
   }

   time time::operator/(const int64 rhs) const
   {
      return time(ticks_ / rhs);
   }

   time time::operator+(const time &rhs) const
   {
      return time(ticks_ + rhs.ticks_);
   }

   time time::operator-(const time &rhs) const
   {
      return time(ticks_ - rhs.ticks_);
   }

   bool time::operator==(const time &rhs) const
   {
      return ticks_ == rhs.ticks_;
   }

   bool time::operator!=(const time &rhs) const
   {
      return ticks_ != rhs.ticks_;
   }

   bool time::operator< (const time &rhs) const
   {
      return ticks_ < rhs.ticks_;
   }

   bool time::operator<=(const time &rhs) const
   {
      return ticks_ <= rhs.ticks_;
   }

   bool time::operator> (const time &rhs) const
   {
      return ticks_ > rhs.ticks_;
   }

   bool time::operator>=(const time &rhs) const
   {
      return ticks_ >= rhs.ticks_;
   }

   int64 time::as_ticks() const
   {
      return ticks_;
   }

   float time::as_seconds() const
   {
      return ticks_ * 0.001f;
   }

   float time::as_milliseconds() const
   {
      return ticks_ * 1.0f;
   }

   namespace {
      template <typename Fn>
      struct scope_guard {
         scope_guard(Fn f) : fn(f) { }
         ~scope_guard() { fn(); }
         Fn fn;
      };

      template <typename Fn>
      scope_guard<Fn> make_scope_guard(Fn f) {
         return scope_guard<Fn>(f);
      }
   } // !anon

   // static
   bool file_system::exists(const string &filename)
   {
      DWORD attrib = GetFileAttributesA(filename.c_str());
      return (attrib != INVALID_FILE_ATTRIBUTES && !(attrib & FILE_ATTRIBUTE_DIRECTORY));
   }

   bool file_system::read_file_content(const string &filename, string &content)
   {
      HANDLE handle = CreateFileA(filename.c_str(),
                                  GENERIC_READ,
                                  FILE_SHARE_READ,
                                  NULL,
                                  OPEN_EXISTING,
                                  FILE_ATTRIBUTE_NORMAL,
                                  NULL);
      if (handle == INVALID_HANDLE_VALUE) {
         return false;
      }

      auto defer = make_scope_guard(([&]() {
         CloseHandle(handle);
      }));

      LARGE_INTEGER size = {};
      if (!GetFileSizeEx(handle, &size)) {
         return false;
      }

      content.resize(size.QuadPart);
      if (!ReadFile(handle, &content[0], size.LowPart, NULL, NULL)) {
         return false;
      }

      if (size.HighPart > 0) {
         if (!ReadFile(handle, &content[0] + size.LowPart, size.HighPart, NULL, NULL)) {
            return false;
         }
      }

      return true;
   }

   bool file_system::read_file_content(const string &filename, dynamic_array<uint8> &content)
   {
      HANDLE handle = CreateFileA(filename.c_str(),
                                  GENERIC_READ,
                                  FILE_SHARE_READ,
                                  NULL,
                                  OPEN_EXISTING,
                                  FILE_ATTRIBUTE_NORMAL,
                                  NULL);
      if (handle == INVALID_HANDLE_VALUE) {
         return false;
      }

      auto defer = make_scope_guard(([&]() {
         CloseHandle(handle);
      }));

      LARGE_INTEGER size = {};
      if (!GetFileSizeEx(handle, &size)) {
         return false;
      }

      content.resize(size.QuadPart);
      if (!ReadFile(handle, content.data(), size.LowPart, NULL, NULL)) {
         return false;
      }

      if (size.HighPart > 0) {
         if (!ReadFile(handle, content.data() + size.LowPart, size.HighPart, NULL, NULL)) {
            return false;
         }
      }

      return true;
   }

   bool file_system::write_file_content(const string &filename, const dynamic_array<uint8> &content, bool allow_overwrite)
   {
      HANDLE handle = CreateFileA(filename.c_str(),
                                  GENERIC_WRITE,
                                  FILE_SHARE_WRITE,
                                  NULL,
                                  allow_overwrite ? CREATE_ALWAYS : CREATE_NEW,
                                  FILE_ATTRIBUTE_NORMAL,
                                  NULL);
      if (handle == INVALID_HANDLE_VALUE) {
         return false;
      }

      auto defer = make_scope_guard(([&]() {
         CloseHandle(handle);
      }));

      if (allow_overwrite) {
         DWORD error = GetLastError();
         if (error != ERROR_ALREADY_EXISTS) {
            return false;
         }
      }

      LARGE_INTEGER size = {};
      size.QuadPart = content.size();
      if (!WriteFile(handle, content.data(), size.LowPart, NULL, NULL)) {
         return false;
      }

      if (size.HighPart > 0) {
         if (!WriteFile(handle, content.data() + size.LowPart, size.HighPart, NULL, NULL)) {
            return false;
         }
      }

      return true;
   }

   // static 
   void mouse::show_cursor(bool state)
   {
      static bool current = true;
      if (current != state) {
         ShowCursor(current = state);
      }
   }

   mouse::mouse()
      : buttons_{}
   {
   }

   point mouse::position() const
   {
      return position_;
   }

   bool mouse::button_down(const button index) const
   {
      return buttons_[int(index)].current_;
   }

   bool mouse::button_pressed(const button index) const
   {
      return buttons_[int(index)].current_ && !buttons_[int(index)].previous_;
   }

   bool mouse::button_released(const button index) const
   {
      return !buttons_[int(index)].current_ && buttons_[int(index)].previous_;
   }

   keyboard::keyboard()
      : keys_{}
   {
   }

   bool keyboard::key_down(const key index) const
   {
      return keys_[int(index)].current_;
   }

   bool keyboard::key_pressed(const key index) const
   {
      return keys_[int(index)].current_ && !keys_[int(index)].previous_;
   }

   bool keyboard::key_released(const key index) const
   {
      return !keys_[int(index)].current_ && keys_[int(index)].previous_;
   }

   namespace {
      bitmap::format determine_pixel_format(const int components)
      {
         switch (components) {
            case 3: return bitmap::format::rgb8;
            case 4: return bitmap::format::rgba8;
         }
         return bitmap::format::unknown;
      }
   } // !anon

   // static 
   bool bitmap::save(const char *filename,
                     const bitmap::format format,
                     const int32 width,
                     const int32 height,
                     const void *data)
   {
      // note: cheating.. just a little!
      bitmap image;
      image.format_ = format;
      image.width_  = width;
      image.height_ = height;
      image.data_   = (uint8 *)data;
      return save(filename, image);
   }

   bool bitmap::save(const char *filename,
                     const bitmap &image)
   {
      assert(image.bytes_per_pixel());
      return stbi_write_png(filename,
                            image.width(),
                            image.height(),
                            image.bytes_per_pixel(),
                            image.data(),
                            image.width() * image.bytes_per_pixel()) == 1;
   }

   bitmap::bitmap()
      : format_(format::unknown)
      , width_(0)
      , height_(0)
      , data_(nullptr)
   {
   }

   bool bitmap::is_valid() const
   {
      return data_ != nullptr;
   }

   bool bitmap::create(const char *filename)
   {
      dynamic_array<uint8> content;
      if (!file_system::read_file_content(filename, content)) {
         return false;
      }

      int width = 0;
      int height = 0;
      int components = 0;
      stbi_uc *data = stbi_load_from_memory(content.data(),
                                            (int)content.size(),
                                            &width,
                                            &height,
                                            &components,
                                            0);
      if (!data) {
         return false;
      }

      format_ = determine_pixel_format(components);
      assert(format_ != bitmap::format::unknown);
      width_  = width;
      height_ = height;
      data_   = data;

      return is_valid();
   }

   bool bitmap::create(const format format, const int32 width, const int32 height)
   {
      format_ = format;
      width_  = width;
      height_ = height;
      data_   = (uint8 *)malloc(bytes_per_pixel() * width_ * height_);
      assert(data_);

      memset(data_, 0, bytes_per_pixel() * width_ * height_);

      return is_valid();
   }

   void bitmap::destroy()
   {
      if (data_) {
         free(data_);
      }

      format_ = format::unknown;
      width_  = 0;
      height_ = 0;
      data_   = nullptr;
   }

   void bitmap::fill(const uint32 color)
   {
      if (!is_valid()) {
         return;
      }

      const uint8 elements[4] = 
      {
         (uint8)((color >> 16) & 0xff), // red
         (uint8)((color >>  8) & 0xff), // green
         (uint8)((color >>  0) & 0xff), // blue
         (uint8)((color >> 24) & 0xff), // alpha
      };
      
      uint8 *dst = data_;
      for (int32 y = 0; y < height_; y++) {
         for (int32 x = 0; x < width_; x++) {
            for (int32 e = 0; e < bytes_per_pixel(); e++) {
               *dst++ = elements[e];
            }
         }
      }
   }

   void bitmap::set_pixel(const int32 x, const int32 y, const uint32 color)
   {
      if (!is_valid()) {
         return;
      }

      if (x < 0 || x >= width_) {
         return;
      }

      if (y < 0 || y >= height_) {
         return;
      }

      const uint8 elements[4] =
      {
         (uint8)((color >> 16) & 0xff), // red
         (uint8)((color >>  8) & 0xff), // green
         (uint8)((color >>  0) & 0xff), // blue
         (uint8)((color >> 24) & 0xff), // alpha
      };

      const int32 bpp   = bytes_per_pixel();
      const int32 index = bpp * width_ * y + bpp * x;
      for (int32 e = 0; e < bpp; e++) {
         data_[index + e] = elements[e];
      }
   }

   bitmap::format bitmap::pixel_format() const
   {
      return format_;
   }

   int32 bitmap::bytes_per_pixel() const
   {
      switch (format_) {
         case bitmap::format::rgb8:  return 3;
         case bitmap::format::rgba8: return 4;
      }
      return 0;
   }

   int32 bitmap::width() const
   {
      return width_;
   }

   int32 bitmap::height() const
   {
      return height_;
   }

   uint8 *bitmap::data() const
   {
      return data_;
   }

   // static 
   bool application::on_error(const char *format, ...)
   {
      char message[4096] = {};
      va_list vargs;
      va_start(vargs, format);
      vsprintf_s(message, format, vargs);
      va_end(vargs);
      
      MessageBoxA(NULL, message, "ERROR!", MB_OK | MB_ICONERROR);

      return false;
   }

   application::application()
   {
   }

   application::~application()
   {
   }

   bool application::on_init()
   {
      return true;
   }

   void application::on_exit()
   {
   }

   bool application::on_tick(const time &deltatime)
   {
      return true;
   }

   void application::on_draw()
   {
   }
} // !avocado

