cmake_minimum_required(VERSION 3.19.6)

### Rodinia Renderer Library ###

project(
	Renderer
	VERSION 0.0.2
	LANGUAGES CXX
)

set(PUBLIC_HEADERS
	"include/Rodinia/Renderer/Base.hpp"
	"include/Rodinia/Renderer/Renderer.hpp"
)

set(PRIVATE_HEADERS

)

set(SRC_FILES
	"src/Renderer.cpp"
)

set(HEADER_FILES
	${PUBLIC_HEADERS}
	${PRIVATE_HEADERS}
)

add_library(Renderer STATIC
	${SRC_FILES}
	${HEADER_FILES}
)

target_link_libraries(Renderer
	PRIVATE Rodinia::Core
)

target_include_directories(Renderer PUBLIC 
	"$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
	"$<INSTALL_INTERFACE:include>"
)

add_library(Rodinia::Renderer ALIAS Renderer)

install(
	TARGETS 
		Renderer 
	EXPORT 
		RendererTargets 
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	RUNTIME DESTINATION bin
	INCLUDES DESTINATION include
)

install(EXPORT RendererTargets
	DESTINATION lib/cmake/Renderer
	FILE RendererTargets.cmake
	NAMESPACE Rodinia::
)

install(DIRECTORY include/
	DESTINATION include/
)