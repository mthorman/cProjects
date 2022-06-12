#Michael Thorman
#CSCI 24000
#9/25/2017
#makefile for assignment#3

Player.exe: Driver.o Player.o
	g++ Driver.o Player.o -o Player.exe
Driver.o: Driver.cpp
	g++ -c Driver.cpp 
Player.o: Player.cpp Player.h
	g++ -c Player.cpp 
clean:
	rm -f Driver.o Player.o 


