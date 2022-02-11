// avocado.hpp

#ifndef AVOCADO_HPP_INCLUDED
#define AVOCADO_HPP_INCLUDED

#include <cassert>
#include <string>
#include <array>
#include <vector>
#include <unordered_map>

namespace avocado {
   typedef unsigned long long uint64;
   typedef   signed long long int64;
   typedef unsigned int       uint32;
   typedef   signed int       int32;
   typedef unsigned short     uint16;
   typedef   signed short     int16;
   typedef unsigned char      uint8;
   typedef   signed char      int8;

   using string = std::string;

   template <typename T, std::size_t S>
   using static_array = std::array<T, S>;

   template <typename T>
   using dynamic_array = std::vector<T>;

   template <typename K, typename V>
   using hash_map = std::unordered_map<K, V>;

   struct debug {
      static bool message_box(const char *caption, const char *format, ...);
      static bool error_box(const char *caption, const char *format, ...);
   };

   struct point {
      point();
      point(const int32 x, const int32 y);

      point operator+(const point &rhs) const;
      point operator-(const point &rhs) const;

      bool operator==(const point &rhs) const;
      bool operator!=(const point &rhs) const;

      int32 x_;
      int32 y_;
   };

   struct time {
      static time deltatime();
      static time now();

      time();
      time(const int64 ticks);
      time(const double seconds);

      time &operator+=(const time &rhs);
      time &operator-=(const time &rhs);
      time operator/(const int64 rhs) const;
      time operator+(const time &rhs) const;
      time operator-(const time &rhs) const;
      bool operator==(const time &rhs) const;
      bool operator!=(const time &rhs) const;
      bool operator< (const time &rhs) const;
      bool operator<=(const time &rhs) const;
      bool operator> (const time &rhs) const;
      bool operator>=(const time &rhs) const;

      int64 as_ticks() const;
      float as_seconds() const;
      float as_milliseconds() const;

      int64 ticks_;
   };

   struct file_system {
      static bool exists(const string &filename);
      static bool read_file_content(const string &filename, string &content);
      static bool read_file_content(const string &filename, dynamic_array<uint8> &content);
      static bool write_file_content(const string &filename, const dynamic_array<uint8> &content, bool allow_overwrite);
   };

   struct mouse {
      static void show_cursor(bool state);

      enum class button {
         left,
         right,
         middle,
         count,
      };

      mouse();

      point position() const;
      bool button_down(const button index) const;
      bool button_pressed(const button index) const;
      bool button_released(const button index) const;

      point position_;
      struct {
         bool current_;
         bool previous_;
      } buttons_[int(button::count)];
   };

   struct keyboard {
      enum class key {
         none,
         back,
         tab,
         clear,
         enter,
         shift,
         control,
         alt,
         pause,
         capslock,
         escape,
         space,
         pageup,
         pagedown,
         end,
         home,
         left,
         up,
         right,
         down,
         printscreen,
         insert,
         del,
         zero,  // 0
         one,   // 1
         two,   // 2
         three, // 3
         four,  // 4
         five,  // 5
         six,   // 6
         seven, // 7
         eight, // 8
         nine,  // 9
         a,
         b,
         c,
         d,
         e,
         f,
         g,
         h,
         i,
         j,
         k,
         l,
         m,
         n,
         o,
         p,
         q,
         r,
         s,
         t,
         u,
         v,
         w,
         x,
         y,
         z,
         keypad0,
         keypad1,
         keypad2,
         keypad3,
         keypad4,
         keypad5,
         keypad6,
         keypad7,
         keypad8,
         keypad9,
         keypadmultiply,
         keypadadd,
         keypadseparator,
         keypadsubtract,
         keypaddecimal,
         keypaddivide,
         f1,
         f2,
         f3,
         f4,
         f5,
         f6,
         f7,
         f8,
         f9,
         f10,
         f11,
         f12,
         numlock,
         scrolllock,
         leftshift,
         rightshift,
         leftcontrol,
         rightcontrol,
         leftalt,
         rightalt,
         oem1,
         oemplus,
         oemcomma,
         oemminus,
         oemperiod,
         oem2,
         oem3,
         oem4,
         oem5,
         oem6,
         oem7,
         oem8,
         oem102,
         count,
      };

      keyboard();

      bool key_down(const key index) const;
      bool key_pressed(const key index) const;
      bool key_released(const key index) const;

      struct {
         bool current_;
         bool previous_;
      } keys_[int(key::count)];
   };

   struct bitmap {
      enum class format {
         rgb8,
         rgba8,
         count,
         unknown,
      };

      static bool save(const char *filename,
                       const bitmap::format format,
                       const int32 width,
                       const int32 height,
                       const void *data);
      static bool save(const char *filename,
                       const bitmap &image);

      bitmap();
      
      bool is_valid() const;
      bool create(const char *filename);
      bool create(const format format, const int32 width, const int32 height);
      void destroy();

      void fill(const uint32 color = 0x00000000u);
      void set_pixel(const int32 x, const int32 y, const uint32 color);

      format pixel_format() const;
      int32 bytes_per_pixel() const;
      int32 width() const;
      int32 height() const;
      uint8 *data() const;

      format format_;
      int32 width_;
      int32 height_;
      uint8 *data_;
   };

   struct settings {
      string title_;
      int32 width_{};
      int32 height_{};
      bool borderless_{};
      bool center_{};
   };

   struct application {
      static application *create(settings &settings);
      static bool on_error(const char *format, ...);

      application();
      virtual ~application();

      virtual bool on_init();
      virtual void on_exit();
      virtual bool on_tick(const time &deltatime);
      virtual void on_draw();

      mouse mouse_;
      keyboard keyboard_;
   };
} // !avocado

#endif // !AVOCADO_HPP_INCLUDED
