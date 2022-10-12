/*
  copyright shawn 2022
  license MIT
  version v3.0
*/

#ifndef CONSOLE_H_
#define CONSOLE_H_
#include <cassert>
#include <iostream>
#include <windows.h>
#define ESC "\x1B"
#define CSI "\x1B["

struct Color {
  int r;
  int g;
  int b;
}back_color = { 0,0,0 }, fore_color = { 255,255,255 };
inline void Clear(int n = 256) {
  std::cout << CSI"0G";
  std::cout << CSI"0d";
  std::cout << CSI << n << 'M';
}
inline Color GetBackColor() { return back_color; }
inline Color GetForeColor() { return fore_color; }
inline void Init() {
  std::ios::sync_with_stdio(false);
  DWORD mode = 0;
  GetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), &mode);
  mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
  SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), mode);
}
inline bool KeyDown(int n) {
  return GetAsyncKeyState(n) & 0x01;
}
inline void SetBackColor(Color c) {
  assert(c.r >= 0);
  assert(c.r <= 255);
  assert(c.g >= 0);
  assert(c.g <= 255);
  assert(c.b >= 0);
  assert(c.b <= 255);
  std::cout << CSI"48;2;" << std::hex << c.r << ';' << c.g << ';' << c.b << 'm';
  std::cout.setf(std::ios_base::basefield);
  back_color = c;
}
inline void SetBackColor(int r, int g, int b) {
  assert(r >= 0);
  assert(r <= 255);
  assert(g >= 0);
  assert(g <= 255);
  assert(b >= 0);
  assert(b <= 255);
  std::cout << CSI"48;2;" << std::hex << r << ';' << g << ';' << b << 'm';
  std::cout.setf(std::ios_base::basefield);
  back_color = { r,g,b };
}
inline void SetForeColor(Color c) {
  assert(c.r >= 0);
  assert(c.r <= 255);
  assert(c.g >= 0);
  assert(c.g <= 255);
  assert(c.b >= 0);
  assert(c.b <= 255);
  std::cout << CSI"38;2;" << std::hex << c.r << ';' << c.g << ';' << c.b << 'm';
  std::cout.setf(std::ios_base::basefield);
  fore_color = c;
}
inline void SetForeColor(int r, int g, int b) {
  assert(r >= 0);
  assert(r <= 255);
  assert(g >= 0);
  assert(g <= 255);
  assert(b >= 0);
  assert(b <= 255);
  std::cout << CSI"38;2;" << std::hex << r << ';' << g << ';' << b << 'm';
  std::cout.setf(std::ios_base::basefield);
  fore_color = { r,g,b };
}

#undef ESC
#undef CSI
#endif // CONSOLE_H_