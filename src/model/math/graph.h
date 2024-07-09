#pragma once

#include <vector>
#include "model/components/map.h"

namespace ge
{

using Adjacency = std::vector<std::vector<float64>>;

class Graph {
public:
  void InitAdjancyMatrix(const Map& map, bool always_twoway);

  Adjacency GetAdjacencyMatrix() const;

private:
  Adjacency adjacency_matrix_;
};

} // namespace ge
