all: main # other_PROJ1exes
.PHONY : all

PROJ1 = main
INSTALL_PATH = build/
SRCS = $(wildcard *.cpp)
 # g++ -c src.cpp -o Output任意名任意后缀, cmake的.o文件被名命为.cpp.o,
 # 后缀不影响目标二进制文件内容
OBJS = $(SRCS:.cpp=.o)
CXX = g++ 
CXXFLAGS += -std=c++11 -pedantic -Wall -Wextra -Og

$(PROJ1): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

include $(SRCS:.cpp=.d)
%.d: %.cpp
	set -e; rm -f $@; \
	$(CXX) -MM $(CXXFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

.PHONY : install
install:
	install $(PROJ1) $(INSTALL_PATH)
	@echo "cp completed"

.PHONY : clean 
clean: 
	-rm -f $(OBJS) $(PROJ1) $(SRCS:.cpp=.d)
