#ifndef FIRST_APP_H
#define FIRST_APP_H

#include "lve_device.h"
#include "lve_pipeline.h"
#include "lve_window.h"

namespace lve {
class FirstApp {
 public:
  static constexpr int WIDTH = 800;
  static constexpr int HEIGHT = 600;

  void run();

 private:
  LveWindow lve_window_{WIDTH, HEIGHT, "Hello world\n"};
  LveDevice lve_device_{lve_window_};
  LvePipeLine lve_pipline_{
      lve_device_, "../shaders/simple_shader.vert.spv",
      "../shaders/simple_shader.frag.spv",
	LvePipeLine::defaultPipelineConfingInfo(WIDTH, HEIGHT)};
};
}  // namespace lve

#endif  // FIRST_APP_H
