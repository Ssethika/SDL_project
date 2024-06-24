#pragma once

// Usefull type definitions to increase speed while programming.
using b8 = bool;

using i8 = char;
using u8 = unsigned char;

using i16 = short;
using u16 = unsigned short;

using i32 = int;
using u32 = unsigned int;

using i64 = long;
using u64 = unsigned long;
using ll = long long;

using f32 = float;
using f64 = double;
using f128 = long double;

// Usefull structs to describe for example the position of a player.

template <typename T> struct v2 {

public:
  T x;
  T y;

  v2(T x, T y) : x(x), y(y) {} 
};

template <typename T> struct v3 {

public:
  T x;
  T y;
  T z;

  v3(T x, T y, T z) : x(x), y(y), z(z) {}
};
