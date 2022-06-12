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
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <stdlib.h>
#include <string>
#include <fstream>
#include "Sort.h"
#include "BubbleSort.h"
#include "InsertionSort.h"



int main() //main function 
{
	int menuResponse; 
	int menuResponse2; 
	int i = 0; 
	int array[50];
	std:: string line; 
	Sort * insertionSortObject = new InsertionSort();
	Sort * bubbleSortObject= new BubbleSort();
	std:: string string_data; 
	std::string fname = "data.txt"; 
	int int_data; 
	std:: stringstream convert;
	std:: stringstream convertline; 
	do
	{
		std:: cout <<" "<<std::endl; 
		std:: cout <<"1. Load Integers (From File)" <<std:: endl; //first user menu 
		std:: cout <<"2. Exit Program" <<std:: endl; 
		std:: cout <<"Please enter your selection: "; 
		std:: cin >> menuResponse; 
		std:: cout <<std::endl; 
		if (menuResponse == 1)
		{
			std::ifstream In(fname.c_str()); //constructor for ifstream takes a const char*, not a string 
			if(In.is_open())
			{
				while(std::getline(In,line))
				{
					convertline.str(line); //convert line to stringstream 
					while(std::getline(convertline, string_data, ','))
					{
						std::stringstream convert(string_data);
						convert >> int_data; 
						array[i] = int_data; 
						i++;
						convert.clear(); 
					}
					std:: cout <<"Unsorted Array: ";
						for(i =0; i<50; i++)
						{
							std:: cout <<array[i]; 
							if (i <(50-1))
							{
								std:: cout <<", "; 
							}
						}
					std::cout<<" "<<std::endl; 
				}
			}
			In.close(); 
			std:: cout <<" "<<std::endl; 
			std:: cout <<"1. Insertion Sort" << std:: endl; 
			std:: cout <<"2. Bubble Sort"<<std::endl;
			std:: cout <<"3. Exit Program"<<std::endl;
			std::cout <<"Please enter your selection: "; 
			std:: cin >> menuResponse2; 
			if (menuResponse2 ==1)
			{
				insertionSortObject->getSortedData(array, 50);  //Calls method getSortedData from InsertionSort class and pass it array and size of array
				
			}
			else if (menuResponse2 ==2)
			{
				bubbleSortObject->getSortedData(array, 50); 
			}
			else if (menuResponse2 ==3)
			{
				std::cout <<"Goodbye!"<<std::endl; 
				delete insertionSortObject;
				delete bubbleSortObject; 
				break; 
			}
			
		}	
		else if (menuResponse == 2) //if user selects option#2 then "Goodbye" will print to screen and the program will exit
		{
			std::cout <<"Goodbye!"<<std::endl; 
			delete insertionSortObject;
			delete bubbleSortObject; 
			break; 
		}
	}while(true);
	
	return 0; 
}