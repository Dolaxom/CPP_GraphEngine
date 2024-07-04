#include <stdexcept>
#include "map.h"

namespace ge {

void Map::AddPoint(float64 x, float64 y) {
  points_.push_back({x, y});
}

void Map::AddRelation(size_t source, size_t destination) {
  auto points_count = points_.size();
  if (source > points_count || destination > points_count) {
    throw std::logic_error("Invalid point index");
  }

  relations_.push_back({source, destination});
}

size_t Map::PointsCount() const {
  return points_.size();
}

size_t Map::RelationsCount() const {
  return relations_.size();
}

Point Map::GetPoint(size_t point_id) const {
  if (point_id >= points_.size()) {
    throw std::runtime_error("Invalid point index");
  }

  return points_[point_id];
}

Relation Map::GetRelation(size_t relation_id) const {
  if (relation_id >= relations_.size()) {
    throw std::runtime_error("Invalid relation index");
  }

  return relations_[relation_id];
}

} // namespace ge
