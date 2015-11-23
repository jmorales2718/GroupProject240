CC = g++
LD = $(CC)

driver: driver.cpp Signal.h DTW.h DTW_GUI.h

Signal.o: Signal.h Signal.cpp

DTW.o: DTW.h DTW.cpp Signal.h 

DTW_GUI.o: DTW_GUI.h DTW_GUI.cpp Signal.h

clean:
	rm -rf *.o driver
