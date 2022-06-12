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

#include <iostream>
#include <string>
#include <cmath>
#include "BubbleSort.h"


BubbleSort::BubbleSort() //Constructor 
{
	
}
BubbleSort::~BubbleSort() //Destructor 
{
	
}
//Methods 
int BubbleSort::getSortedData(int *x, int y) 
{
	int temp; 
	for (int i = 1; i <= y-1; i++) //For first pass there are y-1 or 50-1 comparisons
	{
		for(int j = 0; j <= y-i-1; j++) //For second pass there are y-2 or 50-2 comparisons, so j <=y-1-i 
		{
			if (x[j+1] > x[j]) //compare numbers j and j+1 
			{
				std::swap(x[j], x[j+1]); //swap x[j] and x[j+1]
			}
		}
	}
	std:: cout <<" "<<std:: endl; 
	std:: cout <<"Bubble Sort: ";
	for (int i=0; i < y; i++)
	{
		std:: cout <<x[i]; 
			if (i <(y-1))
			{
				std:: cout <<", "; 
			}
	}
	std:: cout <<" "<<std::endl; 
}
