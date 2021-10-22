cmake_minimum_required(VERSION 3.19.6)

### Rodinia Sandbox Application ###

if(NOT TARGET Rodinia::Core)
	find_Package(Core REQUIRED)
endif()

add_executable(Sandbox 
	"src/Sandbox.cpp"
)

set_property(DIRECTORY ${PROJECT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Sandbox)

target_link_libraries(Sandbox
	PRIVATE Rodinia::Core
)

install(
	TARGETS 
		Sandbox 
	EXPORT 
		SandboxTargets 
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	RUNTIME DESTINATION bin
	INCLUDES DESTINATION include
)

install(EXPORT SandboxTargets
	DESTINATION lib/cmake/Sandbox
	FILE SandboxTargets.cmake
	NAMESPACE Rodinia::
)