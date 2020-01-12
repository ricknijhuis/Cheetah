# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("CheetahV2")

set(APPLICATION_NAME "Game")
set(RENDER_API "OPENGL")

# Platform defines
IF (WIN32)
  add_compile_definitions(CH_PLATFORM_WINDOWS)
ELSE()
  # set stuff for other systems
ENDIF()

# Include sub-projects.
add_subdirectory("Cheetah")
add_subdirectory ("Game")

#print all cmake variables
# macro(print_all_variables)
#     message(STATUS "print_all_variables------------------------------------------{")
#     get_cmake_property(_variableNames VARIABLES)
#     foreach (_variableName ${_variableNames})
#         message(STATUS "${_variableName}=${${_variableName}}")
#     endforeach()
#     message(STATUS "print_all_variables------------------------------------------}")
# endmacro()
# 
# print_all_variables()