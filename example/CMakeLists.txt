cmake_minimum_required(VERSION 3.1)
project(imgui-app)
include_directories(..)

add_compile_definitions(SOKOL_GLCORE33)
add_executable(test ../imgui_app.cpp test.cpp)
add_executable(test_advanced ../imgui_app.cpp test_advanced.cpp)
