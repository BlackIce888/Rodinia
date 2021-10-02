cmake_minimum_required(VERSION 3.19.6)

project(
	RodiniaCore
	VERSION 0.0.1
	LANGUAGES CXX
)

set(SRC_FILES
	src/RodiniaApplication.cpp
)

set(HEADER_FILES
	include/RodiniaCore.h
	src/RodiniaApplication.h
	src/RodiniaEntryPoint.h
	src/RodiniaLogger.h
)

include(${CMAKE_BINARY_DIR}/conan_paths.cmake OPTIONAL)

add_library(${PROJECT_NAME} SHARED
	${SRC_FILES}
	${HEADER_FILES}
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

target_include_directories(${PROJECT_NAME} PUBLIC 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
)

target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})

add_library(Rodinia::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

install(TARGETS ${PROJECT_NAME} EXPORT ${PROJECT_NAME}Targets 
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	RUNTIME DESTINATION bin
	INCLUDES DESTINATION include
)

install(EXPORT ${PROJECT_NAME}Targets
	DESTINATION lib/cmake/${PROJECT_NAME}
	FILE ${PROJECT_NAME}Targets.cmake
	NAMESPACE Rodinia::
)

install(DIRECTORY include/
	DESTINATION include/${PROJECT_NAME}
)