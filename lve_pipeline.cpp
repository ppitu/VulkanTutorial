#include "lve_pipeline.h"

#include <vulkan/vulkan_core.h>

#include <cstddef>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <vector>

namespace lve {
LvePipeLine::LvePipeLine(LveDevice& device, const std::string& vert_file_path,
                         const std::string& frag_file_path,
                         const PipeLineConfigInfo& config_info)
    : lve_device_(device) {
  createGraphicsPipeline(vert_file_path, frag_file_path, config_info);
}

std::vector<char> LvePipeLine::readFile(const std::string& file_path) {
  std::ifstream file{file_path, std::ios::ate | std::ios::binary};

  if (!file.is_open()) {
    throw std::runtime_error("Failed to open file: " + file_path);
  }

  size_t file_size = static_cast<size_t>(file.tellg());
  std::vector<char> buffer(file_size);

  file.seekg(0);
  file.read(buffer.data(), file_size);

  file.close();
  return buffer;
}

void LvePipeLine::createGraphicsPipeline(
    const std::string& vert_file_path, const std::string& frag_file_path,
    const PipeLineConfigInfo& config_info) {
  auto vertCode = readFile(vert_file_path);
  auto fragCode = readFile(frag_file_path);

  std::cout << "Vertex Shader Code Size: " << vertCode.size() << "\n";
  std::cout << "Fragment Shader Code Size: " << fragCode.size() << "\n";
}

void LvePipeLine::createShaderModule(const std::vector<char>& code,
                                     VkShaderModule* shader_module) {
  VkShaderModuleCreateInfo create_info{};
  create_info.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
  create_info.codeSize = code.size();
  create_info.pCode = reinterpret_cast<const uint32_t*>(code.data());

  if (vkCreateShaderModule(lve_device_.device(), &create_info, nullptr,
                           shader_module) != VK_SUCCESS) {
    throw std::runtime_error("Failed to create shader module");
  }
}

PipeLineConfigInfo LvePipeLine::defaultPipelineConfingInfo(uint32_t width,
                                                           uint32_t height) {
  PipeLineConfigInfo config_info{};
  return config_info;
}

}  // namespace lve
