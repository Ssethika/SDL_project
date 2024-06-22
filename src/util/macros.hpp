// Other useful macros to use
#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)
#define CONCAT(a, b) a##b
#define FOR(i, a, end) for (int i = a; i < end, i++)
#define FOR_INCLUSIVE(i, a, end) for (int i = a; i <= end; i++)
#define FOR_REVERSE(i, a, b) for (int i = a; i >= end; i--)
#define FOR_RANGE(a, end) for (int i = a; i < end; i++)
#define ASSERT(x) assert(x)
#define SWAP(x, y)                                                             \
  x = y ^ x;                                                                   \
  y = x ^ y;                                                                   \
  x = y ^ x


