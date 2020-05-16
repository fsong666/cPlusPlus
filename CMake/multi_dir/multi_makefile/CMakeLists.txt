# https://cmake.org/cmake/help/v3.0/manual/cmake-commands.7.html
cmake_minimum_required(VERSION 2.8)
set(PROJNAME main)
project(${PROJNAME} CXX)

FILE(GLOB SRCS_main "main_dir/*.cpp")

# 添加子目录下的CMakeLists.txt
add_subdirectory(other)

INCLUDE_DIRECTORIES( 
	${PROJECT_SOURCE_DIR}/include
)

add_compile_options(
	-std=c++11
	-O0
	-g
	-pedantic
	-Wall
	-Wextra
	-Werror
	-Wno-unused-function
)

add_executable(${PROJNAME} ${SRCS_main})
target_link_libraries(${PROJNAME} FOO_shared)

install(TARGETS ${PROJNAME}
	DESTINATION ${PROJECT_SOURCE_DIR}
)

