cmake_minimum_required(VERSION 3.21)
project(OpenCV_Project CXX)

find_package(OpenCV REQUIRED)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE opencv::opencv LibLZMA::LibLZMA)