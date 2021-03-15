cmake_minimum_required (VERSION 3.0)
project (Assignment_0)

find_package(OpenGL REQUIRED)

# Compile external dependencies 
add_subdirectory (external)

# On Visual 2005 and above, this module can set the debug working directory
cmake_policy(SET CMP0026 OLD)


if(INCLUDE_DISTRIB)
	add_subdirectory(distrib)
endif(INCLUDE_DISTRIB)



include_directories(
	external/AntTweakBar-1.16/include/
	external/glfw-3.1.2/include/
	external/glm-0.9.7.1/
	external/glew-1.13.0/include/
	external/assimp-3.0.1270/include/
	external/bullet-2.81-rev2613/src/
	.
)

set(ALL_LIBS
	${OPENGL_LIBRARY}
	glfw
	GLEW_1130
)

add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)



add_executable(Dodecahedron1
	src/dodecahedron1.cpp
	common/shader.cpp
	common/shader.hpp
	common/controls.cpp
	common/controls.hpp

	src/FragmentShader.fragmentshader
	src/VertexShader.vertexshader
)
target_link_libraries(Dodecahedron1
	${ALL_LIBS}
)

# Xcode and Visual working directories
set_target_properties(Dodecahedron1 PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/")
add_custom_command(
   TARGET Dodecahedron1 POST_BUILD
   COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/Dodecahedron1${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/src/"
)


# add_executable(Dodecahedron2
# 	src/dodecahedron2.cpp
# 	common/shader.cpp
# 	common/shader.hpp
# 	common/controls.cpp
# 	common/controls.hpp

# 	src/FragmentShader.fragmentshader
# 	src/VertexShader.vertexshader
# )
# target_link_libraries(Dodecahedron2
# 	${ALL_LIBS}
# )


# set_target_properties(Dodecahedron2 PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/")
# add_custom_command(
#    TARGET Dodecahedron2 POST_BUILD
#    COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/Dodecahedron2${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/src/"
# )


# add_executable(Dodecahedron3
# 	src/dodecahedron3.cpp
# 	common/shader.cpp
# 	common/shader.hpp
# 	common/controls.cpp
# 	common/controls.hpp
# 	common/texture.cpp
# 	common/texture.hpp
# 	common/objloader.cpp
# 	common/objloader.hpp
# 	common/vboindexer.cpp
# 	common/vboindexer.hpp
# 	common/tangentspace.hpp
# 	common/tangentspace.cpp
# 	common/quaternion_utils.cpp
# 	common/quaternion_utils.hpp

# 	src/FragmentShader.fragmentshader
# 	src/VertexShader.vertexshader
# )
# target_link_libraries(Dodecahedron3
# 	${ALL_LIBS}
# )

# set_target_properties(Dodecahedron3 PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/")
# add_custom_command(
#    TARGET Dodecahedron3 POST_BUILD
#    COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/Dodecahedron3${CMAKE_EXECUTABLE_SUFFIX}" "${CMAKE_CURRENT_SOURCE_DIR}/src/"
# )
