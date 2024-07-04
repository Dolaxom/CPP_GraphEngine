#pragma once

#include <GLFW/glfw3.h>
#include "model/model.h"

namespace ge {

class Window {
 public:
  Window();

  void Create();

 private:
  GLFWwindow *window_;
  Engine engine;

  float cameraX_ = 0.0f;
  float cameraY_ = 0.0f;

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
