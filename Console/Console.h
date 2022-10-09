/*
  copyright shawn 2022
  license MIT
  version v1.0
*/

#ifndef CONSOLE_H_
#define CONSOLE_H_
#include <iostream>
#include <windows.h>
#define ESC "\x1B"
#define CSI "\x1B["

inline void Clear(int n = 256) {
  std::cout << CSI"0G";
  std::cout << CSI"0d";
  std::cout << CSI << n << 'M';
}
inline void Init() {
  std::ios::sync_with_stdio(false);
  DWORD mode = 0;
  GetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), &mode);
  mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
  SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), mode);
}
inline void SetBackColor(int r, int g, int b) {
  std::cout << CSI"48;2;" << std::hex << r << ';' << g << ';' << b << 'm';
  std::cout.setf(std::ios_base::basefield);
}
inline void SetForeColor(int r, int g, int b) {
  std::cout << CSI"38;2;" << std::hex << r << ';' << g << ';' << b << 'm';
  std::cout.setf(std::ios_base::basefield);
}

#undef ESC
#undef CSI
#endif // CONSOLE_H_