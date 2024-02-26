cmake_minimum_required(VERSION 3.5)
project(graphics)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Compiler options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")

# Directories
set(SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/inc)

# Sources
set(SOURCES ${SOURCE_DIR}/main.cpp)

# Includes
include_directories(${INCLUDE_DIR})

# Executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link libraries (assuming SDL2)
find_package(SDL2 REQUIRED)
target_link_libraries(${PROJECT_NAME} SDL2::SDL2)

# Install executable
install(TARGETS ${PROJECT_NAME} DESTINATION bin)

# Create 'run' target
add_custom_target(run
    COMMAND ${PROJECT_NAME}
    DEPENDS ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
