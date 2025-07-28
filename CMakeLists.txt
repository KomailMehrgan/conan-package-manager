cmake_minimum_required(VERSION 3.21)
project(manageAI CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenVINO REQUIRED)
find_package(OpenCV REQUIRED)
find_package(nlohmann_json REQUIRED)

add_executable(manageAI
    manageAI.cpp
    module/rectangle_module.cpp
)


# Only add top-level include — no need to add subfolders manually
target_include_directories(manageAI PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(manageAI PRIVATE
    openvino::openvino
    opencv::opencv
    nlohmann_json::nlohmann_json
)
