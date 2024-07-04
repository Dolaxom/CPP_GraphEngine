#include <fstream>
#include "save.h"

namespace ge
{

using json = nlohmann::json;

void Save::SaveMapToFile(const Map& map) {
  json res;

  res["project"] = "backup";
  res["points"] = json::array();
  
  size_t points_count = map.PointsCount();
  for (size_t id = 0; id < points_count; ++id) {
    res["points"].push_back({ {"x", map.GetPoint(id).x}, {"y", map.GetPoint(id).y} });
  }

  res["relations"] = json::array();
  size_t relations_count = map.RelationsCount();
  for (size_t id = 0; id < relations_count; ++id) {
    res["relations"].push_back({ {"source", map.GetRelation(id).source}, {"destination", map.GetRelation(id).destination} });
  }

  std::ofstream file{"backup.ge"};
  file << res.dump(4);
}

void Save::LoadMapFromFile(std::filesystem::path&& path, Map& map) {
  std::ifstream file{path};

  if (!file.is_open()) {
    throw std::runtime_error("Invalid path to map file");
  }

  std::string map_str{(std::istreambuf_iterator<char>{file}), std::istreambuf_iterator<char>{}};
  json map_json = json::parse(map_str);

  for (const auto& point : map_json["points"]) {
    auto x = point["x"];
    auto y = point["y"];

    map.AddPoint(x, y);
  }

  for (const auto& point : map_json["relations"]) {
    auto s = point["source"];
    auto d = point["destination"];

    map.AddRelation(s, d);
  }
}

} // namespace ge