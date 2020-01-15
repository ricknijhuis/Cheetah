# CMakeList.txt : CMake project for Cheetah, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

#----------------------------------------------
# ADD CHEETAH LIBRARY
#----------------------------------------------

# Define Cheetah variables
set(LIB_DIR "${PROJECT_SOURCE_DIR}/Cheetah/dependencies")
set(INCLUDES_DIR_PUBLIC "${PROJECT_SOURCE_DIR}/Cheetah/includes")
set(INCLUDES_DIR_PRIVATE "${PROJECT_SOURCE_DIR}/Cheetah/src")
set(ENGINE_DIR "${PROJECT_SOURCE_DIR}/Cheetah/src/Engine")
set(ENGINE_CORE_DIR "${ENGINE_DIR}/Core")
set(ENGINE_INPUT_DIR "${ENGINE_DIR}/Input")
set(ENGINE_EVENTS_DIR "${ENGINE_DIR}/Events")
set(ENGINE_RENDERER_DIR "${ENGINE_DIR}/Renderer")
set(ENGINE_DEBUG_DIR "${ENGINE_DIR}/Debug")
set(ENGINE_MATH_DIR "${ENGINE_DIR}/Math")
set(ENGINE_RESOURCES_DIR "${ENGINE_DIR}/Resources")
set(PLATFORM_DIR "${PROJECT_SOURCE_DIR}/Cheetah/src/Platform")
set(PLATFORM_WINDOWS_DIR "${PLATFORM_DIR}/Windows")
set(PLATFORM_OPENGL_DIR "${PLATFORM_DIR}/OpenGL")

# Set default files
list(APPEND SOURCE_FILES 	
	"${ENGINE_DIR}/Engine.h"
	"${ENGINE_CORE_DIR}/Application.h"
	"${ENGINE_CORE_DIR}/Application.cpp"
	"${ENGINE_CORE_DIR}/Core.h"
	"${ENGINE_CORE_DIR}/EntryPoint.h"
	"${ENGINE_CORE_DIR}/Window.h"
	"${ENGINE_CORE_DIR}/UpdateLayer.h"
	"${ENGINE_CORE_DIR}/UpdateLayer.cpp"
	"${ENGINE_CORE_DIR}/UpdateLayerQueue.h"
	"${ENGINE_CORE_DIR}/UpdateLayerQueue.cpp"
	"${ENGINE_CORE_DIR}/Time.h"
	"${ENGINE_CORE_DIR}/Time.cpp"
	"${ENGINE_RENDERER_DIR}/RenderAction.h"
	"${ENGINE_RENDERER_DIR}/RenderAction.cpp"
	"${ENGINE_RENDERER_DIR}/GraphicsContext.h"
	"${ENGINE_RENDERER_DIR}/GraphicsContext.cpp"
	"${ENGINE_RENDERER_DIR}/RenderAPI.h"
	"${ENGINE_RENDERER_DIR}/RenderAPI.cpp"
	"${ENGINE_RENDERER_DIR}/Renderer.h"
	"${ENGINE_RENDERER_DIR}/Renderer.cpp"
	"${ENGINE_RENDERER_DIR}/Renderer2D.h"
	"${ENGINE_RENDERER_DIR}/Renderer2D.cpp"
	"${ENGINE_RENDERER_DIR}/IndexBuffer.h"
	"${ENGINE_RENDERER_DIR}/IndexBuffer.cpp"
	"${ENGINE_RENDERER_DIR}/VertexBuffer.h"
	"${ENGINE_RENDERER_DIR}/VertexBuffer.cpp"
	"${ENGINE_RENDERER_DIR}/VertexArray.h"
	"${ENGINE_RENDERER_DIR}/VertexArray.cpp"
	"${ENGINE_RENDERER_DIR}/Shader.h"
	"${ENGINE_RENDERER_DIR}/Shader.cpp"
	"${ENGINE_RENDERER_DIR}/VertexBufferLayout.h"
	"${ENGINE_RENDERER_DIR}/VertexBufferLayout.cpp"
	"${ENGINE_RENDERER_DIR}/Texture.h"
	"${ENGINE_RENDERER_DIR}/Texture.cpp"
	"${ENGINE_RENDERER_DIR}/OrthoGraphicCamera.h"
	"${ENGINE_RENDERER_DIR}/OrthoGraphicCamera.cpp"
	"${ENGINE_RENDERER_DIR}/Renderer2DQueue.h"
	"${ENGINE_RENDERER_DIR}/Renderer2DQueue.cpp"
	"${ENGINE_INPUT_DIR}/Input.h"
	"${ENGINE_INPUT_DIR}/Input.cpp"
	"${ENGINE_EVENTS_DIR}/ApplicationEvents.h"
	"${ENGINE_EVENTS_DIR}/ApplicationEvents.cpp"
	"${ENGINE_EVENTS_DIR}/Event.h"
	"${ENGINE_EVENTS_DIR}/Event.cpp"
	"${ENGINE_EVENTS_DIR}/EventDispatcher.h"
	"${ENGINE_EVENTS_DIR}/EventDispatcher.cpp"
	"${ENGINE_EVENTS_DIR}/EventTypes.h"
	"${ENGINE_EVENTS_DIR}/InputEvents.h"
	"${ENGINE_EVENTS_DIR}/InputEvents.cpp"
	"${ENGINE_MATH_DIR}/Vector.cpp"
	"${ENGINE_MATH_DIR}/Vector.h"
	"${ENGINE_MATH_DIR}/Vector3.h"
	"${ENGINE_MATH_DIR}/Vector3.inl"
	"${ENGINE_MATH_DIR}/Vector4.h"
	"${ENGINE_MATH_DIR}/Vector4.inl"
	"${ENGINE_MATH_DIR}/Mat4x4.h"
	"${ENGINE_MATH_DIR}/Mat4x4.inl"
	"${ENGINE_MATH_DIR}/Mat4x4.cpp"
	"${ENGINE_MATH_DIR}/Quaternion.h"
	"${ENGINE_MATH_DIR}/Quaternion.inl"
	"${ENGINE_MATH_DIR}/Rgb.h"
	"${ENGINE_MATH_DIR}/Rgba.h"
	"${ENGINE_RESOURCES_DIR}/ResourceCache.h"
	"${ENGINE_RESOURCES_DIR}/ResourceCache.inl"
	"${ENGINE_RESOURCES_DIR}/ResourceLoader.h"
	"${ENGINE_RESOURCES_DIR}/ResourceLoader.cpp"
)
# Set platform specific files
# Windows
list(APPEND SOURCE_FILES_WINDOWS
	"${PLATFORM_WINDOWS_DIR}/WindowsWindow.h"
	"${PLATFORM_WINDOWS_DIR}/WindowsWindow.cpp"
	"${PLATFORM_WINDOWS_DIR}/WindowsTime.h"
	"${PLATFORM_WINDOWS_DIR}/WindowsTime.cpp"
	"${PLATFORM_WINDOWS_DIR}/WindowsInput.h"
	"${PLATFORM_WINDOWS_DIR}/WindowsInput.cpp"
)

# OpenGL
list(APPEND SOURCE_FILES_OPENGL
	"${PLATFORM_OPENGL_DIR}/OpenGLRenderAPI.h"
	"${PLATFORM_OPENGL_DIR}/OpenGLRenderAPI.cpp"
	"${PLATFORM_OPENGL_DIR}/OpenGLGraphicsContext.h"
	"${PLATFORM_OPENGL_DIR}/OpenGLGraphicsContext.cpp"
	"${PLATFORM_OPENGL_DIR}/OpenGLVertexBuffer.h"
	"${PLATFORM_OPENGL_DIR}/OpenGLVertexBuffer.cpp"
	"${PLATFORM_OPENGL_DIR}/OpenGLIndexBuffer.h"
	"${PLATFORM_OPENGL_DIR}/OpenGLIndexBuffer.cpp"
	"${PLATFORM_OPENGL_DIR}/OpenGLShader.h"
	"${PLATFORM_OPENGL_DIR}/OpenGLShader.cpp"
	"${PLATFORM_OPENGL_DIR}/OpenGLVertexArray.h"
	"${PLATFORM_OPENGL_DIR}/OpenGLVertexArray.cpp"
	"${PLATFORM_OPENGL_DIR}/OpenGLTexture.h"
	"${PLATFORM_OPENGL_DIR}/OpenGLTexture.cpp"
)

list(APPEND SOURCE_FILES ${SOURCE_FILES_OPENGL})

# Append Platform specific files
# Operating platform
IF (WIN32)
  list(APPEND SOURCE_FILES ${SOURCE_FILES_WINDOWS})
  # TODO: Linux
  # TODO: MacOS
  # TODO: Android
  # TODO: IOS
ENDIF()

# Add source to this project's executable.
add_library(Cheetah SHARED ${SOURCE_FILES})

target_include_directories (Cheetah INTERFACE ${INCLUDES_DIR_PUBLIC})
target_include_directories (Cheetah PRIVATE ${ENGINE_DIR})
target_include_directories (Cheetah PRIVATE ${INCLUDES_DIR_PRIVATE})

# Add compile definitions
list(APPEND CHEETAH_COMP_DEFS
	"CH_BUILD_DLL"
	${RENDER_API}
)

target_compile_definitions(Cheetah PRIVATE ${CHEETAH_COMP_DEFS})
target_compile_definitions(Cheetah PUBLIC "$<$<CONFIG:DEBUG>:DEBUG>")
target_compile_definitions(Cheetah PUBLIC "$<$<CONFIG:DEBUG>:CH_ASSERT_ENABLED>")

set_target_properties(Cheetah PROPERTIES LINKER_LANGUAGE CXX)
# Copy dll to game project build folder
add_custom_command(
	TARGET Cheetah 
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different
	"${PROJECT_BINARY_DIR}/Cheetah/Cheetah.dll"
	"${PROJECT_BINARY_DIR}/${APPLICATION_NAME}"
)

#----------------------------------------------
# ADD OPENGL LIBRARY DEPENDENCY
#----------------------------------------------
find_package(OpenGL REQUIRED)
target_link_libraries(Cheetah ${OpenGL})

#----------------------------------------------
# ADD GLFW LIBRARY DEPENDENCY
#----------------------------------------------
set(GLFW_DIR "${LIB_DIR}/glfw")
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")
add_subdirectory("${GLFW_DIR}")
target_include_directories(Cheetah PRIVATE "${GLFW_DIR}/include")
target_link_libraries(Cheetah "glfw" "${GLFW_LIBRARIES}")
target_compile_definitions(Cheetah PRIVATE "GLFW_INCLUDE_NONE")

#----------------------------------------------
# ADD GLAD LIBRARY DEPENDENCY
#----------------------------------------------
set(GLAD_DIR "${LIB_DIR}/glad")
add_library("glad" "${GLAD_DIR}/src/glad.c")
target_include_directories("glad" PRIVATE "${GLAD_DIR}/include")
target_include_directories(Cheetah PUBLIC "${GLAD_DIR}/include")
target_link_libraries(Cheetah "glad" "${CMAKE_DL_LIBS}")

#----------------------------------------------
# ADD STB_IMAGE LIBRARY DEPENDENCY
#----------------------------------------------
set(STB_IMAGE_DIR "${LIB_DIR}/stb_image")
add_library("stb_image" "${STB_IMAGE_DIR}/stb_image.cpp")
target_include_directories("stb_image" PRIVATE "${STB_IMAGE_DIR}/include")
target_include_directories(Cheetah PUBLIC "${STB_IMAGE_DIR}/include")
target_link_libraries(Cheetah "stb_image" "${CMAKE_DL_LIBS}")