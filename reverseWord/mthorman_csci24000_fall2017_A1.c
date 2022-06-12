//Honor Pledge:
//
//I pledge that I have neither given nor
//received any help on this assignment.
//
//mthorman

//mthorman_CSCI 24000_Fall 2017_Assignment#1
//9/10/2017
//Create a program that prompts the user to
//enter a word and using a single recursive
//function your job is to invert the word.

#include <stdio.h>
#include <stdlib.h>



// This function uses recursion to reverse user word
void reversedWord (char userWord [], int index, int size) //each of the string will be reversed
{
    char tempWord;
    tempWord = userWord[index];
    userWord[index] = userWord[size - index];
    userWord[size - index] = tempWord;
    if (index == size / 2)
    {
        return;
    }
    reversedWord(userWord, index + 1, size); //recursive equation used to reverse string
}


//main function responsible for running program
int main ()
{
	char userWord [100]; //user's word is stored in char array with 99 characters
	int size;
	char userPrompt;
	printf("Please enter a word: \n"); //user is asked for a word. This is displayed on this screen
	scanf("%s", userWord); //Reads the user's response as a string and the value is stored in userWord
	size = strlen(userWord); //Determines the size of the char array for userWord and that is stored in the integer size
	reversedWord(userWord, 0, size -1); //Calls reverseWord function.
	printf("Your word spelled backwards is: %s \n", userWord); //prints out user's word backwards to screen
	printf("Would you like to continue (Y/N)? "); //Asks the user if they wanted to continue
	scanf(" %c", &userPrompt); //their response is saved in userPrompt
    if (userPrompt == 'N') //if user's response is 'N' then
    {
        printf("Thank you! Goodbye! \n");
        return;
    }
    else {
        return main();
    }
   return 0;
}

