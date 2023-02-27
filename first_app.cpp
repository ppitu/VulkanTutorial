#include "first_app.h"

namespace lve {
  void FirstApp::run() {
    while (!lve_window_.shouldClose()) {
      glfwPollEvents();
    }
  }
}
