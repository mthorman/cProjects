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

import java.util.Scanner;
import java.io.File;
import java.io.IOException;

public class Driver
{
	public static void main(String[]args) //main function
	{
	Scanner input = new Scanner(System.in);
	BubbleSort bubbleSortObject = new BubbleSort(); 
	InsertionSort insertionSortObject = new InsertionSort(); 
	int numbers[] = new int[50]; 
	int i = 0; 
	int menuResponse1;
	int menuResponse2;
	do
	{
		System.out.println(" "); 
		System.out.println("1. Load Integers (From File)");  //first user menu 
		System.out.println("2. Exit Program"); 
		System.out.print("Please enter your selection: "); 
		menuResponse1 = input.nextInt(); 
		if (menuResponse1 == 1)
		{
			try
			{
				File file = new File("data.txt");
				Scanner sc = new Scanner(file);
				String[] tokens = sc.nextLine().split(",");
				numbers = new int[tokens.length];
				for (i = 0; i <tokens.length; i++)
				{
					numbers[i] = Integer.parseInt(tokens[i]); 
				}
				sc.close();
			}
			catch(IOException ex)
			{
				System.err.println(ex);
			}
				System.out.print("Unsorted Array: ");
					for(i =0; i<50; i++)
					{
						System.out.print(numbers[i]); 
						if (i <(50-1))
						{
							System.out.print(", "); 
						}
					}
				System.out.println(" "); 
				
			System.out.println(" "); 
			System.out.println("1. Insertion Sort"); 
			System.out.println("2. Bubble Sort"); 
			System.out.println("3. Exit Program"); 
			System.out.print("Please enter your selection: "); 
			menuResponse2 = input.nextInt(); 
			if (menuResponse2 ==1)
			{			
				insertionSortObject.getSortedData(numbers);  //Calls method getSortedData from InsertionSort class and pass it array and size of array
				
			}
			else if (menuResponse2 ==2)
			{
				bubbleSortObject.getSortedData(numbers); 
			}
			else if (menuResponse2 ==3)
			{
				System.out.println("Goodbye!"); 
				break; 
			}
			
		}	
		else if (menuResponse1 == 2) //if user selects option#2 then "Goodbye" will print to screen and the program will exit
		{
			System.out.println("Goodbye!");
			break; 
		}
	}while(true);
}
}
	