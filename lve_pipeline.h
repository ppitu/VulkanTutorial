#ifndef LVE_PIPELINE_H
#define LVE_PIPELINE_H

#include <vulkan/vulkan_core.h>

#include <cstdint>
#include <string>
#include <vector>

#include "lve_device.h"

namespace lve {
struct PipeLineConfigInfo {};

class LvePipeLine {
 public:
  LvePipeLine(LveDevice& device, const std::string& vert_file_path,
              const std::string& frag_file_path,
              const PipeLineConfigInfo& config_info);
  ~LvePipeLine(){};

  LvePipeLine(const LvePipeLine&) = delete;
  void operator=(const LvePipeLine&) = delete;

  static PipeLineConfigInfo defaultPipelineConfingInfo(uint32_t width,
                                                       uint32_t height);

 private:
  static std::vector<char> readFile(const std::string& file_path);

  void createGraphicsPipeline(const std::string& vert_file_path,
                              const std::string& frag_file_path,
                              const PipeLineConfigInfo& config_info);

  void createShaderModule(const std::vector<char>& code,
                          VkShaderModule* shader_module);

  LveDevice& lve_device_;
  VkPipeline graphics_pipeline_;
  VkShaderModule vert_shader_module_;
  VkShaderModule frag_shader_module_;
};
}  // namespace lve

#endif  // LVE_PIPELINE_H
