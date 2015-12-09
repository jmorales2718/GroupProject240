# File: Makefile

CXX = g++
LD = $(CXX)
RM = /bin/rm -f

FLAGS = -g -Wall -DDEBUG
CXXFLAGS = $(FLAGS) -c
LDFLAGS = $(FLAGS) -o $@

OBJS = driver.o Signal.o DTW.o DTW_GUI.o
EXECS = proj3

all: $(EXECS)

proj3: $(OBJS) 
	$(LD) $(LDFLAGS) $^ 

driver.o: Signal.h DTW.h DTW_GUI.h
	$(CXX) $(CXXFLAGS) driver.cpp

Signal.o: Signal.h
	$(CXX) $(CXXFLAGS) Signal.cpp

DTW.o: DTW.h Signal.h
	$(CXX) $(CXXFLAGS) DTW.cpp

DTW_GUI.o: DTW_GUI.h Signal.h
	$(CXX) $(CXXFLAGS) DTW_GUI.cpp

clean:
	$(RM) $(OBJS) $(EXECS)

