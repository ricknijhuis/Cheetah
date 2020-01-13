# CMakeList.txt : CMake project for Cheetah, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.13)

set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/Game/src")

list(APPEND SOURCE_FILES 
	"${SOURCE_DIR}/Main.cpp"
	"${SOURCE_DIR}/GameLayer.cpp"
	"${SOURCE_DIR}/GameLayer.h"
	"${SOURCE_DIR}/GameObject.h"
	"${SOURCE_DIR}/GameObject.cpp"
	"${SOURCE_DIR}/Scene.h"
	"${SOURCE_DIR}/Scene.cpp"
	"${SOURCE_DIR}/GameScene.h"
	"${SOURCE_DIR}/GameScene.cpp"
)

find_library( CHEETAH_LIB 
	NAMES Cheetah
	HINTS "${CMAKE_BINARY_DIR}/Cheetah")

# Add source to this project's executable.
add_executable (Game ${SOURCE_FILES})

target_include_directories(Game PUBLIC "${PROJECT_SOURCE_DIR}/Cheetah/includes")

# TODO: Add tests and install targets if needed.
target_link_libraries(Game ${CHEETAH_LIB})
