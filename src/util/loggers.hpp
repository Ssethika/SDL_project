#include <iostream>
#include <assert.h>

#define LOG(x) std::cout << x << std::endl
// #endif
#define WARN(x)                                                                \
  std::cout << "\033[33m" << "Warning: " << "\033[0m" << x << std::endl

#define ERROR(x) error(x)

// Assert if something is valid or not. Good for unit testing.

#define ASSERT(x) assert(x)

// Functions that swap the value of two variable.
#define SWAP(x, y)                                                             \
  x = y ^ x;                                                                   \
  y = x ^ y;                                                                   \
  x = y ^ x

inline void error(std::string x) {
  std::cerr << "\033[31m" << "Error:" << "\033[0m" << x << std::endl;
   std::abort();
}
