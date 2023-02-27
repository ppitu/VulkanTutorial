cmake_minimum_required(VERSION 3.20)

project(Tutorial)

set(CMAKE_CXX_STANDARD 20)

find_package(Vulkan REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(Tutorial main.cpp first_app.h first_app.cpp lve_window.h lve_window.cpp lve_device.h lve_device.cpp lve_pipeline.h lve_pipeline.cpp)

target_link_libraries(Tutorial Vulkan::Vulkan)
target_link_libraries(Tutorial glfw)
