cmake_minimum_required(VERSION 3.5)

# Project configuration
project(graphics C CXX)

# Set optimization flags for Release build
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    target_compile_options(my_target PRIVATE -O2)
endif()

# Set C and C++ standards
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Compiler options
set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

find_package(SDL2 REQUIRED)

# Include directories
include_directories(inc)

# Add subdirectory for source files
add_subdirectory(src)

# Install executable
install(TARGETS ${PROJECT_NAME} DESTINATION bin)

# Create 'run' target
add_custom_target(run
    COMMAND ${PROJECT_NAME}
    DEPENDS ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
