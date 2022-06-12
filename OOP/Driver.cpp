//Michael Thorman
//CSCI 24000
//9/25/2017
//
//mthorman_csci24000_fall2017_A3
//The purpose of this assignment is to explore
//two different object-oriented programming
//languages by creating two separate programs -
//one written in C++ and one written in Java.
//In honor of football season, you will create
//players for the IUPUI football team, store
//them in memory, and allow the user to view an
//en entire "roster" of players.
//
//Honor Pledge:
//
//I pledge that I have neither given nor
//received any help on this assignment.
//
//mthorman

#include <iostream>
#include "Player.h"
#include <string>

//main function that runs program
int main()
{
    Player * playerArray = new Player[11]; //creates array on heap
    int p = 0;
    int userResponse;
    Player newPlayer;
    std::string firstName;
    std::string lastName;
    int playerNumber;

    std::cout <<"Welcome to our CSCI 240 Roster Editor! \n" << std:: endl;
    while (p <=11) //While loop for if the elements in array are less than or equal to 11
    {
        std::cout <<"1) Add New Player" <<std::endl; //Menu for user
        std::cout <<"2) View Player(s)" <<std::endl;
        std::cout <<"3) Exit Program \n" <<std:: endl;
        std::cout <<"Please enter your selection: "; //prompts user to enter a selection from the previous 3 choices
        std::cin >> userResponse;
        std::cout <<std::endl;
             if (userResponse == 1){  //Conditional for if the user selects option 1
                std:: cout<< "Please enter a first name: ";
                std:: cin >> firstName;
                std:: cout <<"Please enter a last name: ";
                std:: cin >> lastName;
                std:: cout << "Please enter a number (1-99): ";
                std::cin >> playerNumber;
                newPlayer.setFirstName(firstName);  //the values for firstName, lastName, and playerNumber are passed to set functions for class Player
                newPlayer.setLastName(lastName);
                newPlayer.setPlayerNumber(playerNumber);
                std::cout <<std::endl;
                playerArray[p] = newPlayer; //newPlayer is equal to element of array
                p = p+1;
                std::cout <<"**Player Created**\n" <<std::endl;
             }
            else if (userResponse == 2) //if the user selects option#2 and there is a value stored in the array, then it will print the following
	    {
		std::cout << "**IUPUI Football Roster**" << std::endl;
		for (p=0; p<=11; p++){
                	std::cout << playerArray[p].getPlayerNumber() << ") " << playerArray[p].getFirstName() << " " << playerArray[p].getLastName() << std::endl;
                	std::cout << "*************************" << std::endl;
                	std::cout << std::endl;
		}
            }

            else if (userResponse == 3){  //Else if conditional for if user's response is 3
                std::cout <<"Thank you for using our program - Goodbye!";
		delete[]playerArray; //deletes playerArray from heap
                break;

                }
            else { //Else conditional for if user's response is not 1, 2 or 3
                std::cout <<"Invalid Choice! Please select Option #1, #2, or #3." <<std::endl;
                std::cout <<std::endl;
                }

    }
    delete[]playerArray;
    return 0;
}
