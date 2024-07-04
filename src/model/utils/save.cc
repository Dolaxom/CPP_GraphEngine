#include <fstream>
#include "save.h"

namespace ge
{

using json = nlohmann::json;

void Save::SaveMapToFile(const Map& map) {
  json res;

  res["project"] = "backup";
  res["lines"] = json::array();
  
  size_t points_count = map.PointsCount();
  for (size_t id = 0; id < points_count; ++id) {
    res["lines"].push_back({ {"x", map.GetPoint(id).x}, {"y", map.GetPoint(id).y} });
  }

  res["relations"] = json::array();
  size_t relations_count = map.RelationsCount();
  for (size_t id = 0; id < relations_count; ++id) {
    res["relations"].push_back({ {"source", map.GetRelation(id).source}, {"destination", map.GetRelation(id).destination} });
  }

  std::ofstream file{"backup.ge"};
  file << res.dump(4);
}

} // namespace ge