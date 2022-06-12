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
#include <string>

#ifndef PLAYER_H
#define PLAYER_H


class Player
{
    public:
        Player(); //Default Constructor
        Player(std::string, std::string, int); //overloaded constructor

        ~Player();
        //Accessor Functions
        std::string getFirstName() const;
        int getPlayerNumber() const;
        std::string getLastName() const;
        //Mutator Functions
        void setFirstName(std::string);
        void setLastName(std::string);
        void setPlayerNumber(int);


    private:
        std::string newFirstName;
        std::string newLastName;
        int newPlayerNumber;

};

#endif // PLAYER_H
