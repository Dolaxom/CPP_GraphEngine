cmake_minimum_required(VERSION 3.10)
project(GraphEngine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(glfw3 3.3 REQUIRED)

add_executable(
    GraphEngine
    src/main.cc
    
    src/view/window.cc
    src/view/window.h

    src/model/structs.h
    src/model/model.h
    src/model/model.cc
    src/model/components/map.h
    src/model/components/map.cc
    src/model/components/render.h
    src/model/components/render.cc
)

include_directories(
    third_party/imgui
    third_party/imgui/backends
    src
)

target_link_libraries(GraphEngine OpenGL glfw)
