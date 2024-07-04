#pragma once

#include "model/components/map.h"
#include "nlohmann/json.hpp"

namespace ge
{

class Save {
public:
  static void SaveMapToFile(const Map& map);

private:
};

} // namespace ge
