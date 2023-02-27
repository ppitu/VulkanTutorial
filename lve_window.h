#ifndef LVEWINDOW_H
#define LVEWINDOW_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <string>

namespace lve {

class LveWindow {
 public:
  LveWindow(int w, int h, const std::string& window_name);
  ~LveWindow();

  LveWindow(const LveWindow&) = delete;
  LveWindow &operator=(const LveWindow&) = delete;
  
  bool shouldClose() { return glfwWindowShouldClose(window_); }

  void createWindowSurface(VkInstance instance, VkSurfaceKHR* surface);
  
 private:
  void initWindow();
  
  const int width_;
  const int height_;

  std::string window_name_;
  GLFWwindow* window_;
};

}  // namespace lve

#endif  // LVEWINDOW
