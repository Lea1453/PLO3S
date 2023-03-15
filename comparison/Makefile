CC = gcc
CXX = g++

CFLAGS = -Wall -g
CXXFLAGS = -Wall -g -std=c++11 `pkg-config --cflags opencv`

DIRTOOLS=../../utilTools
DIRVISUALIZE=../../visualizeTools

INCLUDES = -I../../utilTools -I../../visualizeTools

LFLAGS =
LIBS = `pkg-config --libs opencv` -lOpenCL -lboost_iostreams -lboost_system -lboost_filesystem

# define the C/C++ source files
CSRCS = 
CXXSRCS = $(DIRTOOLS)/gradient.cpp $(DIRTOOLS)/arrDeriv.cpp $(DIRTOOLS)/secondDeriv.cpp scoreDistCvxLocal.cpp $(DIRTOOLS)/utilTool.cpp $(DIRTOOLS)/stats.cpp $(DIRTOOLS)/openCLTools.cpp 

COBJS = $(CSRCS:.c=.o)
CXXOBJS = $(CXXSRCS:.cpp=.o)


MAIN = scoreDistCvxLocal




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
