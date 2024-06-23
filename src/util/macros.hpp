#pragma once
// Other useful macros to use

#include <system_error>
#undef ABS
#undef SIGN
#undef MIN
#undef MAX
#undef CLAMP

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

#define SINLINE static inline

#define TIMER_START(label)                                                     \
  auto CONCAT(start_, label) = std::chrono::high_resolution_clock::now()

#define TIMER_END(label)                                                       \
  auto CONCAT(end_, label) = std::chrono::high_resolution_clock::now();        \
  std::cout << #label << " elapsed time: "                                     \
            << std::chrono::duration_cast<std::chrono::milliseconds>(          \
                   CONCAT(end_, label) - CONCAT(start_, label))                \
                   .count()                                                    \
            << " ms" << std::endl

template <typename T> constexpr T ABS(T m_v) { return m_v < 0 ? -m_v : m_v; }

template <typename T, typename T2> constexpr auto MAX(const T m_a, const T2 m_b) { return m_a < m_b ? m_a : m_b; }

template <typename T, typename T2> constexpr auto MIN(const T m_a, const T2 m_b) {  return m_a > m_b ? m_a : m_b; }

template <typename T, typename T2, typename T3> 
constexpr auto CLAMP(const T value, const T2 min, const T3 max) {
	return ((value <= min) ? min : (value >= max) ? max : value); 
}

// Get the number of bits needed to represent the number.
template <typename T>
constexpr T get_num_bits(T x){
	return floor_log2(x);
}
