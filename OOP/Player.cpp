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

#include "Player.h"
#include <iostream>
#include <string>

Player::Player()
{
   newPlayerNumber = 0;
}
Player::Player(std::string fname, std::string lname, int number){
    newFirstName = fname;
    newLastName = lname;
    newPlayerNumber = number;
}
Player::~Player()
{
    //dtor
}
std::string Player:: getFirstName() const{
    return newFirstName;
}
std::string Player:: getLastName() const{
    return newLastName;
}
int Player::getPlayerNumber() const{
    return newPlayerNumber;
}
void Player::setFirstName(std::string fname){
    newFirstName = fname;
}
void Player::setLastName(std::string lname){
    newLastName = lname;
}
void Player::setPlayerNumber(int number){
    newPlayerNumber = number;
}
