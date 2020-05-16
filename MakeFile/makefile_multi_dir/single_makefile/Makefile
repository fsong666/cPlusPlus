all: main # other_projexes
.PHONY : all

PROJ = main
SRCS_MAIN_PATH = main_dir/
SRCS_OTHER_PATH = other/
INCLUDE_PATH = include/
INSTALL_PATH = build/
SRCS_withPath= $(wildcard $(SRCS_MAIN_PATH)*.cpp $(SRCS_OTHER_PATH)*.cpp)
# notdir把展开的文件去除掉路径信息
SRCS = $(notdir $(SRCS_withPath))
OBJS = $(patsubst %.cpp,%.o,$(SRCS)) 
.PHONY : print
print:
	@echo $(SRCS_withPath)
	@echo $(SRCS)
	@echo $(OBJS)
	@echo $(SRCS:.cpp=.d)

CXX = g++ 
CXXFLAGS += -std=c++11 -pedantic -Wall -Wextra -Og
CXXFLAGS += -I$(INCLUDE_PATH)
# -I是为g++编译器指定,头文件路径, vpath是为makefile更新规则指定路径
# VPATH多目录由“冒号”分隔
# vpath 当依赖文件在当前目录找不到时，makefile就在vpath指定的目录查找
# vpath 自动补全依赖路劲，　main_dir/main.cpp foo/foo.hpp
VPATH := $(INCLUDE_PATH):$(SRCS_MAIN_PATH):$(SRCS_OTHER_PATH)

# 隐规则默认从当前路径找.o对应的.cpp/.c文件,若没找到，再从VPATH指定的路径找
# 找到的依赖文件并自动补全.　
# foo.o: foo.cpp # foo.c vpath 搜索后 变为foo/foo.cpp,目标文件.o文件和路径不变!!!!
#   g++ -c foo.cpp $(CFLAGS)
$(PROJ): $(OBJS)
	@echo $(OBJS)
	@echo $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# 为每个源文件自动生成　依赖文件.d 
# g++ -std=c++11 -MM -Iinclude path/src.cpp 
# (通过VPATH)path指明源文件路径， -Iinclude指明头文件路径,所以可以在任意目录位置打印任意源文件的依赖，多目录自动生成依赖的原理
include $(SRCS:.cpp=.d)
%.d: %.cpp
	set -e; rm -f $@; \
	$(CXX) -MM $(CXXFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

# vpath 查找补全路径后等于
# main.o: src/main.cpp include/foo.hpp
# main.o: main.cpp foo.hpp
# 	$(CXX) -c $(CXXFLAGS) $< -o $@
# 	@echo build main.o

# foo.o: foo.cpp foo.hpp
# 	$(CXX) -c $(CXXFLAGS) $< -o $@
# 	@echo build foo.o

.PHONY : install
install:
	install $(PROJ) $(INSTALL_PATH)
	@echo "cp completed"

.PHONY : clean 
clean: 
	-rm -f $(OBJS) $(PROJ) $(SRCS:.cpp=.d)
