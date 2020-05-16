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

aux_source_directory(. DIR_LIB_SRCS)

add_library (FOO_static STATIC ${DIR_LIB_SRCS})
add_library (FOO_shared SHARED ${DIR_LIB_SRCS})

# SET_TARGET_PROPERTIES 改变目标属性　比如名字
SET_TARGET_PROPERTIES (FOO_static PROPERTIES OUTPUT_NAME "FOO")
SET_TARGET_PROPERTIES (FOO_shared  PROPERTIES OUTPUT_NAME "FOO")

MESSAGE (STATUS "This is the FOO_static OUTPUT_NAME: " ${OUTPUT_VALUE})