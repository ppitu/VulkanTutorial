#include "lve_window.h"

#include <GLFW/glfw3.h>
#include <vulkan/vulkan_core.h>
#include <stdexcept>

namespace lve {

LveWindow::LveWindow(int w, int h, const std::string& window_name)
    : width_{w}, height_{h}, window_name_{window_name} {
  initWindow();
}

LveWindow::~LveWindow() {
  glfwDestroyWindow(window_);
  glfwTerminate();
}

void LveWindow::initWindow() {
  glfwInit();
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  window_ =
      glfwCreateWindow(width_, height_, window_name_.c_str(), nullptr, nullptr);
}

  void LveWindow::createWindowSurface(VkInstance instance, VkSurfaceKHR *surface) {
    if(glfwCreateWindowSurface(instance, window_, nullptr, surface) != VK_SUCCESS) {
      throw std::runtime_error("Failed to create window surface");
    }
  }
  
}  // namespace lve
