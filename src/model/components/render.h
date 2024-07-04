#pragma once

#include <vector>
#include "model/components/map.h"
#include "model/structs.h"

namespace ge
{

class Render {
public:
  Render(Map& map);

  void Draw();

private:
  Map& map_;
};

} // namespace ge
