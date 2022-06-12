#Michael Thorman
#CSCI 24000
#11/26/2017
#makefile for assignment#6

Driver.exe: Driver.o BubbleSort.o InsertionSort.o 
	g++ Driver.o BubbleSort.o InsertionSort.o -o Driver.exe
Driver.o: Driver.cpp
	g++ -c Driver.cpp 
BubbleSort.o: BubbleSort.cpp BubbleSort.h
	g++ -c BubbleSort.cpp
InsertionSort.o: InsertionSort.cpp InsertionSort.h
	g++ -c InsertionSort.cpp
Sort.o: Sort.h
	g++ -c Sort.h
clean:
	rm -f Driver.o BubbleSort.o InsertionSort.o Sort.o Driver.exe


