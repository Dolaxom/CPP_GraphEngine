#pragma once

#include <GLFW/glfw3.h>

namespace ge
{

using int64 = long long;

class Grid {
public:
  Grid(int64 w, int64 h) : w_{w}, h_{h} { }

  void Draw() {
    float colors[3] = {0.2f, 0.4f, 0.5f};
    auto count = 50;
    for (double i = -count; i < count; i += step_) {
      glColor3f(colors[0], colors[0], colors[0]);
      glBegin(GL_LINES);
      glVertex2d(-w_, i);
      glVertex2d(w_, i);

      glVertex2d(i, -h_);
      glVertex2d(i, h_);
      glEnd();
    }
    glColor3f(colors[1], colors[2], colors[1]);
    glBegin(GL_LINES);
    glVertex2d(-w_, 0);
    glVertex2d(w_, 0);
    glVertex2d(0, -h_);
    glVertex2d(0, h_);
    glEnd();
  }

private:
  int64 w_;
  int64 h_;
  double step_ = 0.5;
};

} // namespace ge
