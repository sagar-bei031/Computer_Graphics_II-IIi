cmake_minimum_required(VERSION 3.5)

# Project configuration
project(graphics C CXX)

# Set C and C++ standards
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Compiler options for debug build
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

# Compiler options for release build
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")

# Compiler options for warning flags
set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

find_package(SDL2 REQUIRED)

include_directories(inc)

add_executable(graphics
	src/DDA.cpp
	src/BLA.cpp
	src/MCA.cpp
	src/MEA.cpp
	src/vector2.cpp
	src/rectangle.cpp
	src/LineClipper.cpp
	example.cpp
)

target_include_directories(graphics PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(${PROJECT_NAME} SDL2::SDL2)

# Install executable
install(TARGETS ${PROJECT_NAME} DESTINATION bin)

# Create 'run' target
add_custom_target(run
    COMMAND ${PROJECT_NAME}
    DEPENDS ${PROJECT_NAME}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
