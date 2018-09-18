main:	bp.o impbp.o 
	g++	 bp.o impbp.o 

bp.o: bp.cpp
	g++  -c bp.cpp -std=c++11

impbp.o: impbp.cpp 
	g++	-c impbp.cpp -std=c++11

funbp.o: funbp.h 
	g++ -c funbp.h -std=c++11

clean:
	rm *.o
