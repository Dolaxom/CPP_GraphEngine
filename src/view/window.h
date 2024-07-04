#pragma once

#include <GLFW/glfw3.h>
#include "model/engine.h"

namespace ge {

class Window {
 public:
  Window();

  void Create();

 private:
  GLFWwindow *window_;
  Engine engine;

  void SetProjection(int width, int height) const;
  void InitFrame(GLFWwindow *window, int &width, int &height) const;
  void InitWindow();
  void InitOpenGL() const;
  void MainLoop();
  void InitAll();
  void DestroyAll();

  void Draw();
};

}  // namespace ge
