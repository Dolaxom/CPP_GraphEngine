#pragma once

#include <vector>
#include "components/map.h"
#include "components/render.h"
#include "model/math/graph.h"

namespace ge
{

class Engine {
public:
  Engine();
  ~Engine();

  Map GetMap() const {
    return map_;
  }

  Render GetRender() const {
    return render_;
  }

private:
  Map map_;
  Render render_;
  Graph graph_;
};

} // namespace ge
