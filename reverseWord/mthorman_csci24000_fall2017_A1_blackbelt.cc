//Honor Pledge:
//
//I pledge that I have neither given nor
//received any help on this assignment.
//
//mthorman

//mthorman_CSCI 24000_Fall 2017_Assignment#1 Blackbelt
//9/10/2017
//Create a program that prompts the user to
//enter a word and using a single recursive
//function your job is to invert the word
//in C++.

#include <iostream>
using namespace std;


// This function takes information from main function, reverses it, and returns it to main function
void Reverse(char userWord[])
{
    if (*userWord =='\0')
    {
        return;
    }
    else
    {
        Reverse(userWord+1);
        cout<<*(userWord);
    }
}


//main function responsible for running program
int main()
{
    char userWord[100];
    char userPrompt;
    bool run = true;
    while (run)
    {
        cout << "Please enter a word: " << endl;  //"Please enter a word is printed to the screen
        cin.getline(userWord, sizeof(userWord));
        cout <<"Your word spelled backwards is: " << endl; //The word is printed backwards
        Reverse(userWord);
        cout <<endl;
        cout <<"Would you like to continue (Y/N)?" << endl; //The user is asked if they want to continue
        cin >>userPrompt;
        if (userPrompt == 'N') {       //if they type "N" then the program will end
            cout << "Thank you! Goodbye!";
            run = false;
    }
        else {
            continue;
    }
    }
    return 0;
}

