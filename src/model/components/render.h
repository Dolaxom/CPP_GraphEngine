#pragma once

#include <vector>
#include "model/components/map.h"
#include "model/structs.h"
#include "subcomponents/grid.h"

namespace ge
{

class Render {
public:
  Render(Map& map);

  void Draw();

private:
  Map& map_;
  Grid grid_;
};

} // namespace ge
