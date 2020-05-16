#.o .d 文件会在各自子目录生成, exe会在当前目录生成
all: main # other_projexes
.PHONY : all

PROJ = main
SRCS_MAIN_PATH = main_dir/
SRCS_OTHER_PATH = other/
INCLUDE_PATH = include/
INSTALL_PATH = build/
SRCS_withPath= $(wildcard $(SRCS_MAIN_PATH)*.cpp $(SRCS_OTHER_PATH)*.cpp)
OBJS = $(patsubst %.cpp,%.o,$(SRCS_withPath)) 
.PHONY : print
print:
	@echo $(SRCS_withPath)
	@echo $(OBJS)

# export 把变量传给下层子目录中的makefile
export CXX = g++ 
export CXXFLAGS += -std=c++11 -pedantic -Wall -Wextra -Og
CXXFLAGS += -I$(INCLUDE_PATH)

VPATH := $(INCLUDE_PATH):$(SRCS_MAIN_PATH):$(SRCS_OTHER_PATH)

$(PROJ): $(OBJS)
	@echo -----to build $(OBJS)
	@echo -----to build $(SRCS_withPath)
	$(CXX) $(CXXFLAGS) -o $@ $^

# make预设变量$(MAKE) == make
$(SRCS_MAIN_PATH)main.o: main.cpp foo.hpp
	cd $(SRCS_MAIN_PATH) && $(MAKE)
	@echo -------built main.o-----

$(SRCS_OTHER_PATH)foo.o: foo.cpp foo.hpp
	$(MAKE) -C $(SRCS_OTHER_PATH)
	@echo -------built foo.o-----

.PHONY : install
install:
	install $(PROJ) $(INSTALL_PATH)
	@echo "cp completed"

.PHONY : clean 
clean: 
	-rm -f $(OBJS) $(PROJ) 
	$(MAKE) -C $(SRCS_MAIN_PATH) clean
	$(MAKE) -C $(SRCS_OTHER_PATH) clean