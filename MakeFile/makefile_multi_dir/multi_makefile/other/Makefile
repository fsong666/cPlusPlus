SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

INCLUDE_PATH = ../include/
MAIN_Makefile_PATH = ../
CXXFLAGS += -I$(INCLUDE_PATH)
VPATH := $(INCLUDE_PATH)

include $(SRCS:.cpp=.d)
%.d: %.cpp
	set -e; rm -f $@; \
	$(CXX) -MM $(CXXFLAGS) $< > $@.$$$$; \
	sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
	rm -f $@.$$$$

.PHONY : clean 
clean: 
	-rm -f $(OBJS) $(SRCS:.cpp=.d)