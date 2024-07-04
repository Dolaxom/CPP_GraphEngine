#pragma once

#include <filesystem>
#include "model/components/map.h"
#include "nlohmann/json.hpp"

namespace ge
{

class Save {
public:
  static void LoadMapFromFile(std::filesystem::path&& path, Map& map);
  static void SaveMapToFile(const Map& map);

private:
};

} // namespace ge
