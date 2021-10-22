cmake_minimum_required(VERSION 3.19.6)

### Rodinia Core Library ###

project(
	Core
	VERSION 0.0.3
	LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)

set(PUBLIC_HEADERS
	"include/Rodinia/Core/Base.hpp"
	"include/Rodinia/Core/Application.hpp"
	"include/Rodinia/Core/EntryPoint.hpp"
	"include/Rodinia/Core/Logger.hpp"
)

set(PRIVATE_HEADERS
)

set(SRC_FILES
	"src/Application.cpp"
	"src/Logger.cpp"
)

set(HEADER_FILES
	${PUBLIC_HEADERS}
	${PRIVATE_HEADERS}
)

set(UNIT_FILES
	"tests/main.cpp"
	"tests/ApplicationUnit.cpp"
) 

find_package(spdlog REQUIRED)

add_library(Core STATIC
	${SRC_FILES}
	${HEADER_FILES}
)

target_link_libraries(Core
	PUBLIC spdlog::spdlog
)

target_include_directories(Core PUBLIC 
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>"
	"$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

add_library(Rodinia::Core ALIAS Core)

### UNIT TESTS ###

add_executable(CoreUnit
	${UNIT_FILES}
)

target_link_libraries(CoreUnit
	PRIVATE Rodinia::Core
	PRIVATE Catch2::Catch2
)

add_test(NAME CoreUnit
         COMMAND CoreUnit -r junit)

##################

install(
	TARGETS
		Core
		CoreUnit 
	EXPORT 
		CoreTargets
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	RUNTIME DESTINATION bin
	INCLUDES DESTINATION include
)

install(EXPORT CoreTargets
	DESTINATION lib/cmake/Core
	FILE CoreTargets.cmake
	NAMESPACE Rodinia::
)

install(DIRECTORY include/
	DESTINATION include/
)