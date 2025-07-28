cmake_minimum_required(VERSION 3.21)
project(manageAI CXX)

# Set a C++ standard that is compatible with OpenVINO's dependencies.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find the OpenVINO package provided by Conan
find_package(OpenVINO REQUIRED)
find_package(OpenCV REQUIRED)

# Add our executable program
add_executable(main main.cpp)

# Link our program against the OpenVINO library
target_link_libraries(main PRIVATE openvino::openvino opencv::opencv LibLZMA::LibLZMA)


