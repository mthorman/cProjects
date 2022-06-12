/**
*Michael Thorman
*CSCI 24000
*9/25/2017
*
*mthorman_csci24000_fall2017_A3
*The purpose of this assignment is to explore
*two different object-oriented programming
*languages by creating two separate programs -
*one written in C++ and one written in Java.
*In honor of football season, you will create
*players for the IUPUI football team, store
*them in memory, and allow the user to view an
*entire "roster" of players.
*
*Honor Pledge:
*
*I pledge that I have neither given nor
*received any help on this assignment.
*
*mthorman
*/

import java.io.*;
import java.util.Scanner;

public class Driver
{
    public static void main(String [] args)  //Main method
    {
        Player[] playerArray = new Player[11]; //Creates array of 11 elements or players
        int p = 0;
        int userResponse;
        Player newPlayer = new Player();  //Creates object of class Player
        String firstName;
        String lastName;
        int playerNumber;

        System.out.println("Welcome to our CSCI 240 Roster Editor! \n");
        while (p <=11) //while loop for while p is less than or equal to 11 
        {
          Scanner input = new Scanner (System.in);
          System.out.println("1) Add New Player"); //Menu options 
          System.out.println("2) View Player(s)");
          System.out.println("3) Exit Program \n");
          System.out.print("Please enter your selection: ");
          userResponse = input.nextInt();
            if (userResponse == 1)  //if conditional statement for if user selects option#1
                {

                    System.out.print("\n");
                    System.out.print("Please enter a first name: ");
                    firstName = input.next();
                    System.out.print("Please enter a last name: ");
                    lastName = input.next();
                    System.out.print("Please enter a number (1-99): ");
                    playerNumber = input.nextInt();
                    newPlayer.setFirstName(firstName);  //the values stored in variables are then passed to set methods for object newPlayer of class Plaer
                    newPlayer.setLastName(lastName);
                    newPlayer.setPlayerNumber(playerNumber);
                    playerArray[p] = newPlayer; //newPlayer is equal to element of array
                    p++; //elements in array go up by 1 
                    System.out.print("\n");
                    System.out.println("**Player Created**\n");
		    

                }
            else if(userResponse ==2) //else if conditional statement for if user selects option#2
            {	
			System.out.print("\n");
                	System.out.println( "**IUPUI Football Roster**");
				for (p=0 ; p <= playerArray.length; p++);   //loops through array
				{
					if (!playerArray[p].equals(null))
						System.out.println(playerArray[p].getPlayerNumber() + ") " + playerArray[p].getFirstName() + " " + playerArray[p].getLastName());
                				System.out.println("*************************"); 
						

		}	 	
 	 
            }
            else if (userResponse ==3) //if else conditional statement for if user selects option#3
            {
                System.out.print("\n");
                System.out.println("Thank you for using our program - Goodbye!");
                break; //exits program 
            }
            else
            {
                System.out.print("\n");
                System.out.println("Invalid Choice! Please select Option #1, #2, or #3.");
            }
        }
    }
}

