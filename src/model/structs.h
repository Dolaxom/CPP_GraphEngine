#pragma once

#include <cstddef>

namespace ge
{

using float64 = double;

struct Point {
  float64 x;
  float64 y;
};

struct Relation {
  size_t source;
  size_t destination; 
};

} // namespace ge
