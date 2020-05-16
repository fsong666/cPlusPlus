cmake_minimum_required(VERSION 2.8)
set(PROJNAME main)
set(CMAKE_SOURCE_DIR ./)

project(${PROJNAME} CXX)
aux_source_directory(. SRCS)

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


add_executable(${PROJNAME} ${SRCS})
add_library(foo_static STATIC foo.cpp)
add_library(foo_shared SHARED foo.cpp)