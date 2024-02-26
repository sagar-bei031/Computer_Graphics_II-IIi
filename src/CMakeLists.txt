add_executable(graphics
	main.cpp
	DDA.cpp
	BLA.cpp
	MCA.cpp
	MEA.cpp
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(${PROJECT_NAME} SDL2::SDL2)