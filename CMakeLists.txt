cmake_minimum_required(VERSION 2.6)
project(3Douay)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

set(CMAKE_CXX_FLAGS "-g -Wall")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

find_package(SFML 1.6 REQUIRED system window graphics network audio)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

include_directories(${GLEW_INCLUDE_DIR})
include_directories(${SFML_INCLUDE_DIR})
include_directories(${OPENGL_INCLUDE_DIR})

set(mainLibs ${SFML_LIBRARIES} ${GLEW_LIBRARY} ${OPENGL_LIBRARIES})



INCLUDE_DIRECTORIES( assimp/code/BoostWorkaround )
ADD_DEFINITIONS( -DASSIMP_BUILD_BOOST_WORKAROUND )
MESSAGE( STATUS "Building a non-boost version of Assimp." )
add_subdirectory( assimp/code )


file(
	GLOB_RECURSE
	MAIN_SOURCES
	src/*
)

add_executable(3Douay ${MAIN_SOURCES})

target_link_libraries(3Douay ${mainLibs} assimp)