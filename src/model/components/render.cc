#include <GLFW/glfw3.h>

#include "render.h"

#include <iostream>

namespace ge
{

Render::Render(Map& map) : map_{map} {
  
}

void Render::Draw() {
  size_t relations_count = map_.RelationsCount();
  for (size_t id = 0; id < relations_count; ++id) {
    auto relation = map_.GetRelation(id);
    auto point_source = map_.GetPoint(relation.source);
    auto point_destination = map_.GetPoint(relation.destination);
    glColor3f(1, 0.3, 0.3);
    glBegin(GL_LINES);
    glVertex2d(point_source.x, point_source.y);
    glVertex2d(point_destination.x, point_destination.y);
    glEnd();
  }

  size_t points_count = map_.PointsCount();
  for (size_t id = 0; id < points_count; ++id) {
    auto point = map_.GetPoint(id);
    glColor3f(1, 1, 1);
    glBegin(GL_POINTS);
    glVertex2d(point.x, point.y);
    glEnd();
  }
}

} // namespace ge