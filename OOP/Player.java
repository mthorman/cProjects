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

public class Player  //defines class Player
{
    private int playerNumber;
    private String firstName;
    private String lastName;
	//constructor
   public Player() //Default constructor
	{
	}


    public Player(int playerNumber, String firstName, String lastName)
    {
        this.playerNumber = playerNumber;
        this.firstName = firstName;
        this.lastName = lastName;
    }
    //Methods
    public int getPlayerNumber() //getters
    {
        return this.playerNumber;
    }
    public String getFirstName()
    {
        return this.firstName;
    }
    public String getLastName()
    {
        return this.lastName;
    }
    public void setPlayerNumber(int playerNumber) //setters
    {
        this.playerNumber = playerNumber;
    }
    public void setFirstName(String firstName)
    {
        this.firstName = firstName;
    }
    public void setLastName(String lastName)
    {
        this.lastName = lastName;
    }
}
