cmake_minimum_required(VERSION 3.10)
project(GraphEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

include_directories(${CONAN_INCLUDE_DIRS_NLOHMANN_JSON})

add_executable(
    GraphEngine
    src/main.cc
    
    src/view/window.cc
    src/view/window.h

    src/model/structs.h
    src/model/engine.h
    src/model/engine.cc
    src/model/components/map.h
    src/model/components/map.cc
    src/model/components/render.h
    src/model/components/render.cc

    src/model/utils/save.h
    src/model/utils/save.cc
)

include_directories(
    third_party/imgui
    third_party/imgui/backends
    src
)

target_link_libraries(GraphEngine OpenGL glfw)
