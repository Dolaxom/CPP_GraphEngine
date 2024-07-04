#pragma once

#include <vector>
#include "components/map.h"
#include "components/render.h"

namespace ge
{

class Engine {
public:
  Engine();
  ~Engine();
  Map map_;
  Render render_;
private:
};

} // namespace ge
