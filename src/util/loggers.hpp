#pragma once
#include <assert.h>
#include <iostream>

#define LOG(x) std::cout << x << std::endl
// #endif
#define WARN(x)                                                                \
  std::cout << "\033[33m" << "Warning: " << "\033[0m" << x << std::endl


// Functions that swap the value of two variable.
#define SWAP(x, y)                                                             \
  x = y ^ x;                                                                   \
  y = x ^ y;                                                                   \
  x = y ^ x

inline void ERROR(std::string x) {
  std::cerr << "\033[31m" << "Error:" << "\033[0m" << x << std::endl;
  std::abort();
}
