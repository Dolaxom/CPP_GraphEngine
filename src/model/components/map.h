#pragma once

#include <vector>
#include "model/structs.h"

namespace ge
{

using std::vector;

class Map {
public:
  Map() = default;

  void AddPoint(float64 x, float64 y);
  void AddRelation(size_t source, size_t destination);

  size_t PointsCount();
  size_t RelationsCount();
  Point GetPoint(size_t point_id);
  Relation GetRelation(size_t relation_id);

private:
  vector<Point> points_;
  vector<Relation> relations_;
};

} // namespace ge
