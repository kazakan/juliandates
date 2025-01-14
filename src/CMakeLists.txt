# Library target
add_library(juliandates
    juliandates.cpp
)

# Specify include directories for the library
target_include_directories(juliandates PUBLIC ${CMAKE_SOURCE_DIR}/include)