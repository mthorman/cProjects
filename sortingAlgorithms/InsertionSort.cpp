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
#include "InsertionSort.h"

InsertionSort::InsertionSort() 
{
}
InsertionSort::~InsertionSort() 
{
}
int InsertionSort::getSortedData(int *x, int y) 
{
	for (int i =0; i <y; i++) //variable i begins at index 1 of array; loop through each element of array until i < y
	{
		for(int j=i; j>0; j--) //variable j begins at index i of array; if j>0 and array index j is more than array index j -1 then swap the numbers
			if(x[j] >x[j-1]) 
			{
				std::swap (x[j], x[j-1]);
			}
			else 
			{
				break; //otherwise don't swap and break from loop 
			}
	}	
	std:: cout <<" "<<std::endl; 
	std:: cout <<"Insertion Sort: "; 
	for (int i=0; i < y; i++) //print off each element of newly sorted array
	{
		std:: cout <<x[i]; 
			if (i <(y-1))
			{
				std:: cout <<", "; 
			}
	}
	std:: cout <<" "<<std::endl; 
}