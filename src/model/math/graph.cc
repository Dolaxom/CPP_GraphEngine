#include "graph.h"
#include <cmath>

namespace ge
{

void Graph::InitAdjancyMatrix(const Map& map, bool always_twoway) {
  size_t points_count = map.PointsCount();
  size_t relations_count = map.RelationsCount();

  adjacency_matrix_.resize(points_count);
  for (auto& row : adjacency_matrix_) {
    row.resize(points_count);
  }

  for (size_t i = 0u; i < relations_count; ++i) {
    auto relation = map.GetRelation(i);

    auto source = map.GetPoint(relation.source);
    auto destionation = map.GetPoint(relation.destination);

    auto length = std::sqrt(std::pow(destionation.x - source.x, 2) + std::pow(destionation.y - source.y, 2));

    adjacency_matrix_[relation.source][relation.destination] = length;
    
    if (always_twoway) {
      adjacency_matrix_[relation.destination][relation.source] = length;
    }
  }
}

Adjacency Graph::GetAdjacencyMatrix() const {
  return adjacency_matrix_;
}


} // namespace ge
