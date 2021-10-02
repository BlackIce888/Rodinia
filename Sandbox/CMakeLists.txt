cmake_minimum_required(VERSION 3.19.6)

project(Sandbox)

if(NOT TARGET Rodinia::RodiniaCore)
	find_Package(RodiniaCore CONFIG REQUIRED)
endif()

add_executable(${PROJECT_NAME} src/Sandbox.cpp)

target_link_libraries(${PROJECT_NAME} 
	PRIVATE 
		Rodinia::RodiniaCore
)

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