cmake_minimum_required(VERSION 3.1)
project(imgui-app)
include_directories(..)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)

add_executable(test ../imgui_app.cpp test.cpp)
add_executable(test_advanced ../imgui_app.cpp test_advanced.cpp)

if (APPLE)
  add_compile_definitions(SOKOL_METAL)
   target_compile_options(test PRIVATE -x objective-c++)
    target_link_libraries(test PUBLIC
        "-framework QuartzCore"
        "-framework Cocoa"
        "-framework MetalKit"
        "-framework Metal")
   target_compile_options(test_advanced PRIVATE -x objective-c++)
    target_link_libraries(test_advanced PUBLIC
        "-framework QuartzCore"
        "-framework Cocoa"
        "-framework MetalKit"
        "-framework Metal")
else()
  add_compile_definitions(SOKOL_GLCORE33)
endif()
