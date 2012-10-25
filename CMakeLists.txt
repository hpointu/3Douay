cmake_minimum_required(VERSION 2.6)
project(3Douay)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

set(CMAKE_CXX_FLAGS "-g -Wall")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

find_package(PkgConfig REQUIRED)
find_package(SFML 1.6 REQUIRED system window graphics network audio)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
pkg_check_modules(SDL sdl REQUIRED)
pkg_check_modules(SDL_IMAGE SDL_image REQUIRED)

include_directories(${GLEW_INCLUDE_DIR})
include_directories(${SFML_INCLUDE_DIR})
include_directories(${OPENGL_INCLUDE_DIR})
include_directories(${SDL_INCLUDE_DIRS})
include_directories(${SDL_IMAGE_INCLUDE_DIRS})

set(mainLibs ${SFML_LIBRARIES} ${GLEW_LIBRARY} ${OPENGL_LIBRARIES} ${SDL_LIBRARIES} ${SDL_IMAGE_LIBRARIES})

MESSAGE( STATUS "CMake ASSIMP" )
add_subdirectory( assimp-3.0 )
include_directories("assimp-3.0/include")


file(
	GLOB_RECURSE
	MAIN_SOURCES
	src/*
)

add_executable(3Douay ${MAIN_SOURCES})

target_link_libraries(3Douay ${mainLibs} assimp)

configure_file(res/3D/tower.blend 3D/tower.blend COPYONLY)
configure_file(res/3D/tower.png 3D/tower.png COPYONLY)
configure_file(res/textures/sample.png textures/sample.png COPYONLY)
