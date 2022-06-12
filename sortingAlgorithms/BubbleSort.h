//Michael Thorman
//CSCI 24000
//11/23/2017
//
//Use the four pillars of the Object-Oriented paradigm to 
//produce a program that sorts a list of numbers in descending order
//using either Insertion Sort or Bubble Sort. Also, provide runtime 
//analysis of your program. 
//
//Honor Pledge:
//
//I pledge that I have neither given nor
//received any help on this assignment.
//
//mthorman
#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <iostream>
#include <string>
#include <cmath>
#include "Sort.h"


class BubbleSort: public Sort 
{
	public:
		BubbleSort(); //Default Constructor 
		virtual~BubbleSort(); //Destructor 
		//Methods
		virtual int getSortedData(int[], int);
	
};
#endif // BUBBLESORT_H