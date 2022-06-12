//Michael Thorman
//CSCI 24000
//9/25/2017
//
//mthorman_csci24000_fall2017_A2
//The purpose of this assignment is to explore
//how to use pointers, functions, and conditionals
//C++ to create a simulation of the popular children's
//game Candy Land. In the "game" two players will
//attempt to be the first to successfully reach King
//Kandy at the Candy Castle through a series of random
//chance movements. The goal is for you to be the first
//to reach the Castle and win the game.
//
//Honor Pledge:
//
//I pledge that I have neither given nor
//received any help on this assignment.
//
//mthorman


#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>

#define GAME_LENGTH 50


void advancePlayerA(int* ptrPlayerA) //takes the pointer value for playerA and adds a random number to it.
{
    //std:: cout << *ptrPlayerA <<std:: endl;

    int arrDraws[10] = {1,1,1,1,2,2,3,5,-3,-5};  //this array includes all of the possible draws as well as their probabilities
     int newDraw= arrDraws[rand()%10]; //a new integer newDraw is created and a random number from array is created and stored in newDraw
     *ptrPlayerA = *ptrPlayerA + newDraw; //the random number stored in newDraw is added to pointer and passed back to main
     //std:: cout <<newDraw <<std:: endl;
     //std:: cout <<*ptrPlayerA <<std:: endl;

}
void advancePlayerB(int* ptrPlayerB)
{
    //std:: cout << *ptrPlayerB <<std:: endl;
    int arrDraws[10] = {1,1,1,2,3,3,-3,-3,-5};
    int newDraw = arrDraws[rand()%10];
    *ptrPlayerB = *ptrPlayerB + newDraw;
    //std:: cout <<newDraw <<std:: endl;
    //std:: cout <<*ptrPlayerB <<std:: endl;

}

void printPosition (int* ptrPlayerA, int* ptrPlayerB) {//takes the values passed by reference and prints them to screen in a certain format
    //std::cout <<*ptrPlayerA <<std:: endl;
    //std::cout <<*ptrPlayerB <<std:: endl;
    if (*ptrPlayerA < *ptrPlayerB){   //conditional for if pointer A is less than pointer B
    std::cout <<std::setw(*ptrPlayerA);
    std::cout <<"A" ;
    std::cout <<std::setw(*ptrPlayerB - *ptrPlayerA);
    std::cout <<"B" ;
    std::cout <<std::setw(GAME_LENGTH -*ptrPlayerB)<<"|" <<std::endl;
    }
    else if(*ptrPlayerA > *ptrPlayerB){//conditional for if pointer A is greater than pointer B
    std::cout <<std::setw(*ptrPlayerB);
    std::cout <<"B";
    std::cout <<std::setw(*ptrPlayerA- *ptrPlayerB);
    std::cout <<"A" ;
    std::cout <<std::setw(GAME_LENGTH - *ptrPlayerA)<<"|" <<std::endl;
    }
    else if(*ptrPlayerA == 0 && *ptrPlayerB == 0){ //conditional for if the pointers are both equal to 0
    std::cout <<std::setw(*ptrPlayerA);
    std::cout <<"A";
    std::cout <<std::setw(*ptrPlayerA -*ptrPlayerB);
    std::cout <<"B";
    std::cout <<std::setw(GAME_LENGTH -*ptrPlayerB)<<"|" <<std::endl;
    }



}

int main()  //main function initializes program
{
    int playerA = 0; //set player A space to 0
    int playerB = 0; //set player B space to 0
    srand(time(NULL));
    std:: cout <<"Welcome to CSCI 240's Candy Land Game!" <<std:: endl;
    advancePlayerA(&playerA); //pass by reference value for playerA
    //std::cout <<playerA <<std::endl;
        if (playerA <0){   //conditional for if playerA is less than 0
            playerA = 0;
        }
    advancePlayerB(&playerB); //pass by reference value for playerB
    //std::cout <<playerB <<std:: endl;
        if (playerB <0){  //conditional for if playerB is less than 0
            playerB = 0;
        }
    while (playerA == playerB){ //conditional for if player A and player B occupy same space. Player A moves back 1.
        playerA = playerA -1;
    }
    printPosition(&playerA, &playerB); //the values for playerA and playerB are passed by reference to printPosition()


    while (playerA < GAME_LENGTH && playerB < GAME_LENGTH){ //loop for if playerA && playerB are below 50.
    advancePlayerA(&playerA);
    //std:: cout <<playerA <<std::endl;
        if (playerA <0){
            playerA = 0;
        }
        else if (playerA > GAME_LENGTH){
            playerA = GAME_LENGTH;
        }
    advancePlayerB(&playerB);
    //std::cout <<playerB <<std::endl;
        if (playerB <0){
            playerB = 0;
        }
        else if(playerB > GAME_LENGTH){
            playerB = GAME_LENGTH;
        }
        else if (playerA == playerB){
        playerA = playerA -1;
    }
         printPosition(&playerA, &playerB);


    while (playerA == GAME_LENGTH){  //if player A reaches 50 then "You have reached Candy Castle 1st!" will print on screen.
            std:: cout <<"You have reached Candy Castle 1st!" ;
            break;
    }
    while (playerB == GAME_LENGTH){ //if player B reaches 50 then "Your friend reached Candy Castle 1st! Better luck next time." will print to screen
            std:: cout <<"Your friend reached Candy Castle 1st! Better luck next time.";
            break;
           }

    }

    }

