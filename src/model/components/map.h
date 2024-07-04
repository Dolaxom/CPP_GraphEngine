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

  size_t PointsCount() const;
  size_t RelationsCount() const;
  Point GetPoint(size_t point_id) const;
  Relation GetRelation(size_t relation_id) const;

private:
  vector<Point> points_;
  vector<Relation> relations_;
};

} // namespace ge
