cmake_minimum_required(VERSION 3.19.6)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
    message(FATAL_ERROR "Build out-of-source. Delete CMakeCache.txt and the CMakeFiles/ directory and build inside a build directory.")
endif()

project(
	Rodinia
	VERSION 0.0.3
	LANGUAGES CXX
)

find_package(Catch2 REQUIRED)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_compile_definitions(RODINIA_PLATFORM_WINDOWS RODINIA_BUILD_DLL)

enable_testing()

add_subdirectory(Rodinia/Core)
add_subdirectory(Rodinia/Renderer)
add_subdirectory(Sandbox)
