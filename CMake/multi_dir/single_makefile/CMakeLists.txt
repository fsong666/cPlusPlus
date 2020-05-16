# https://cmake.org/cmake/help/v3.0/manual/cmake-commands.7.html
cmake_minimum_required(VERSION 2.8)
set(PROJNAME main)
project(${PROJNAME} LANGUAGES  CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# configure_file 配置文件，让你可以在代码文件中使用CMake中定义的的变量,
# 就是生成存放#define 宏变量的头文件,然后被源文件include调用,记得在源文件头加入#include "config.h"
configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
)


FILE(GLOB SRCS_main "main_dir/*.cpp")
FILE(GLOB SRCS_foo "foo_dir/*.cpp")

INCLUDE_DIRECTORIES( 
	${PROJECT_SOURCE_DIR}/foo_dir
	${PROJECT_SOURCE_DIR}/include
	${PROJECT_SOURCE_DIR}/build
)

add_compile_options(
	-O0
	-g
	-pedantic
	-Wall
	-Wextra
	-Werror
	-Wno-unused-function
)


# 1.直接所有源文件一起编译
# add_executable(${PROJNAME} ${SRCS_main} ${SRCS_foo} ${SRCS_func})

# 2.通过库形式链接, 优点，项目结构清晰
#other_objs 是目标名，不是变量名!!!!
# cmake -D USE_MYFUNC=ON path 
option (USE_MYFUNC "Use provided math implementation" OFF)
if (USE_MYFUNC)
	message("defined USE_MYFUNC!!!!!!!!!!")
	INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/func_dir)
	FILE(GLOB SRCS_func "func_dir/*.cpp")
	add_library(other_objs STATIC ${SRCS_foo} ${SRCS_func})
else ()
	message("not defined USE_MYFUNC!!!!!!!!!!")
	add_library(other_objs STATIC ${SRCS_foo})
endif()	 

add_executable(${PROJNAME} ${SRCS_main})
target_link_libraries (${PROJNAME} other_objs)

# 错误 ${other_objs}!!!! 是other_objs
# 错误undefined reference　来自未找到库文件
# target_link_libraries (${PROJNAME} ${other_objs})
# SET_TARGET_PROPERTIES(${PROJNAME} PROPERTIES LINKER_LANGUAGE CXX)

# DESTINATION 默认路径是/usr/local/
install(TARGETS ${PROJNAME}
	DESTINATION ${PROJECT_SOURCE_DIR}
)

# option变量，不仅可以作为源文件里的#define宏变量(像 USE_MYFUNC)，还仅仅只作为一个cmake的选择变量，这个变量不传到源程序里,也接无需进入config.h
option(MYTEST "Use cmake test" OFF)
if(MYTEST1)
	message("defined MYTEST1!!!!!!!!!!")	
	enable_testing()
	# add_test(NAME <name> COMMAND <command> [<arg>...]) 
	add_test(test_2_5 ${PROJNAME} 2 5)
	# 通过执行文件的打印信息，正则匹配字符串，是否正确
	set_tests_properties (test_2_5 PROPERTIES PASS_REGULAR_EXPRESSION "is 10")

	add_test(test_10_2 ${PROJNAME} 10 2)
	set_tests_properties (test_10_2 PROPERTIES PASS_REGULAR_EXPRESSION "is 20")

	# 测试帮助信息是否可以正常提示
	add_test (test_-2_7 ${PROJNAME} -2 7)
	set_tests_properties (test_-2_7 PROPERTIES PASS_REGULAR_EXPRESSION "is -14")
endif(MYTEST1)


option(MYTEST2 "Use cmake test with macro" OFF)
if(MYTEST2)
	# 定义一个宏，用来简化测试工作
	message("defined MYTEST2 with macro!!!!!!!!!!")
	enable_testing()
	macro (do_test arg1 arg2 result)
	add_test (test_${arg1}_${arg2} main ${arg1} ${arg2})
	set_tests_properties (test_${arg1}_${arg2}
		PROPERTIES PASS_REGULAR_EXPRESSION ${result})
	endmacro (do_test)
	

	# 使用该宏进行一系列的数据测试
	do_test (5 2 "is 10") 	
	do_test (10 5 "is 50")
	do_test (2 -10 "is -20")
endif(MYTEST2)



