cmake_minimum_required(VERSION 3.5.0)
project(juliandates VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add subdirectories
add_subdirectory(src)
add_subdirectory(tests)

enable_testing()

