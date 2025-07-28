cmake_minimum_required(VERSION 3.21)
project(OpenCV_Conan_Demo CXX)

# Find all the packages provided by Conan.
# Each find_package call makes the corresponding targets available.
find_package(OpenCV REQUIRED)
find_package(nlohmann_json REQUIRED)

# Add our executable program
add_executable(main main.cpp)

# Link our program against all the required libraries
target_link_libraries(
    main
    PRIVATE
    opencv::opencv
    LibLZMA::LibLZMA
    nlohmann_json::nlohmann_json
)
