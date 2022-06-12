//Michael Thorman
//CSCI 24000
//11/23/2017
//Assignment#6 Blackbelt 
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

import java.io.*;

public class InsertionSort extends Sort
{
	public InsertionSort()
	{
		super(); 
	}
	public void getSortedData(int x[])
	{
	int y = x.length; 
	for (int i =0; i <y; i++) //variable i begins at index 1 of array; loop through each element of array until i < y
	{
		for(int j=i; j>0; j--) //variable j begins at index i of array; if j>0 and array index j is more than array index j -1 then swap the numbers
			if(x[j] >x[j-1]) 
			{
				int temp = x[j];
				x[j] = x[j-1];
				x[j-1] = temp; 
			}
			else 
			{
				break; //otherwise don't swap and break from loop 
			}
	}	
	System.out.println(" ");
	System.out.print("Insertion Sort: "); 
	for (int i=0; i < y; i++) //print off each element of newly sorted array
	{
		System.out.print(x[i]);
			if (i <(y-1))
			{
				System.out.print(", "); 
			}
	}
	System.out.println(" ");	
	}
	
}
