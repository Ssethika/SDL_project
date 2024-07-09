#pragma once
#include <assert.h>
#include <iostream>

#define DEBUG

#ifdef DEBUG
#define LOG(x) std::cout << x << std::endl
// #endif
#define WARN(x)                                                                \
  std::cout << "\033[33m" << "Warning: " << "\033[0m" << x << std::endl
// Functions that swap the value of two variable.
#else
#define LOG(x)
#define WARN(X) 
#endif


inline void ERROR(std::string x) {
  std::cerr << "\033[31m" << "Error:" << "\033[0m" << x << std::endl;
  std::abort();
}
