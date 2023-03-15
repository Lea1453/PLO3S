CC = gcc
CXX = g++

CFLAGS = -Wall -g
CXXFLAGS = -Wall -g -std=c++11 `pkg-config --cflags opencv`

DIRTOOLS=../utilTools

INCLUDES = -I../utilTools

LFLAGS =
LIBS = `pkg-config --libs opencv` 

# define the C/C++ source files
CSRCS = 
CXXSRCS = convexity.cpp toolConvexity.cpp $(DIRTOOLS)/gradient.cpp $(DIRTOOLS)/secondDeriv.cpp $(DIRTOOLS)/arrDeriv.cpp $(DIRTOOLS)/utilTool.cpp 

COBJS = $(CSRCS:.c=.o)
CXXOBJS = $(CXXSRCS:.cpp=.o)


MAIN = convex




all:    $(MAIN)

$(MAIN): $(COBJS) $(CXXOBJS) 
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(MAIN) $(COBJS) $(CXXOBJS) $(LFLAGS) $(LIBS)
.c.o:
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $<  -o $@
.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) *.o *~ $(MAIN)

depend: $(CSRCS) $(CXXSRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend depends on it. 
