//Abdel Elkasaby, CS162
//10/20/22

//Password Generator

/*
This code takes in a word from the user and then applies a series
of functions to turn the word into a complex password. It turns
the last character to its ASCII value, turns all uppercases to lowercase,
duplicates all vowels, and turns all E's to 3's. If there are no uppercases
an "!" is added to the end. Then it asks the user if they want to try it again.
*/

#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

//constants
const int SIZE = 100;

//prototypes
void manager();
void welcomeUser();
void getInput(char input[], char password[]);
void lastToAscii(char password[], char asciiArray[]);
void upperToLower(char password[], char tempPassword[]);
void eToThree(char password[]);
void duplicateVowel(char password[], char tempPassword2[]);
void printNewPassword(char input[], char password[]);
void tryAgain();

int main()
{
	welcomeUser();
	manager();

	return 0;
}

//used to call other functions
void manager()
{
	char input[SIZE] = {'\0'}; //word inputted from user
	char password[SIZE] = {'\0'}; //password with final modifications
	char tempPassword[SIZE] = {'\0'}; //temp array used to make modifications in upperToLower()
	char tempPassword2[SIZE] = {'\0'}; //temp array used to make modifications in duplicateVowel()
	char asciiArray[SIZE] = {'\0'}; //array used to hold the ascii value so it can be added to array

	getInput(input, password); //get user input

	lastToAscii(password, asciiArray);
	upperToLower(password, tempPassword);
	eToThree(password);
	duplicateVowel(password, tempPassword2);

	printNewPassword(input, password);
	tryAgain();
}

//welcome the user and explain the program
void welcomeUser()
{
	//welcome the user
	cout << endl << "Hello, welcome to the password generator!"
			" This program will help you"
	     << endl << "generate a strong password that you can remember."
			" It will take a word"
	     << endl << "that you choose and modify it so that you can use"
			" it as a password."
	     << endl << endl;
}

//prompt user for input and store it in an array
void getInput(char input[], char password[])
{
	//prompt user for input
	cout << endl << "Enter a word: ";
	cin.get(input, SIZE, '\n');
	cin.ignore(100, '\n');

	//copy word to a new array to make modifications
	for (int i = 0; i <= strlen(input); i++)
	{
		password[i] = input[i];
	}
}

//converts the last character of the original word to its ascii value
void lastToAscii(char password[], char asciiArray[])
{
	char lastChar = password[strlen(password) - 1]; //last character of password
	int ascii = lastChar; //turns it to ascii value

	sprintf(asciiArray, "%d", ascii); //turns ascii value to char array
	password[strlen(password) - 1] = '\0'; //removes last character of password
	strcat(password, asciiArray); //add ascii value to the end of password
}

//changes all uppercase to lowercase and places an "_" before them
//if there are no uppercase letters a '!' is added to the end
void upperToLower(char password[], char tempPassword[])
{
	bool uppercase = false; //to check for uppercase letters
	int pos; //used for the length of tempPassword

	//loop through turn all caps to lowercase
	for (int i = 0; i <= strlen(password); i++)
	{
		pos = strlen(tempPassword);

		//for uppercase letters
		if (isupper(password[i]))
		{
			uppercase = true;
			password[i] = tolower(password[i]);
			tempPassword[pos+1] = password[i];
			tempPassword[pos] = '_';
		}

		//for anything thats not uppercase
		else
		{
			tempPassword[pos] = password[i];
		}
	}

	//if there are no uppercase letters
	if (uppercase == false)
	{
		tempPassword[strlen(password)] = '!';
	}

	//copy word back to the original array
	for (int j = 0; j <= strlen(tempPassword); j++)
	{
		password[j] = tempPassword[j];
	}

	tempPassword[0] = '\0';
}

//turns all E's to 3
void eToThree(char password[])
{
	for (int i = 0; i <= strlen(password); i++)
	{
		if (password[i] == 'e' || password[i] == 'E')
		{
			password[i] = '3';
		}
	}
}

//duplicates all vowels
void duplicateVowel(char password[], char tempPassword2[])
{
	int pos;

	for (int i = 0; i <= strlen(password); i++)
	{
		pos = strlen(tempPassword2);

		tempPassword2[pos] = password[i];

		//for all vowels
		if (password[i] == 'a' || password[i] == 'e' ||
		    password[i] == 'i' || password[i] == 'o' ||
		    password[i] == 'u')
		{
			tempPassword2[pos+1] = password[i];
		}
	}

	//copy back into original array
	for (int j = 0; j <= strlen(tempPassword2); j++)
	{
		password[j] = tempPassword2[j];
	}

	tempPassword2[0] = '\0';
}

//prints out original word and final password
void printNewPassword(char input[], char password[])
{
	cout << endl << "Original Word: " << input << endl;
	cout << "New Password: " << password << endl << endl;
}

//prompts user if they want to try again
void tryAgain()
{
	char response[SIZE];

	cout << "Do you want to try again? Y or N: ";
	cin.get(response, SIZE, '\n');
	cin.ignore(100, '\n');

	if (toupper(response[0]) == 'Y')
	{
		manager();
	}
	else
	{
		cout << "Thanks for playing!" << endl << endl;
	}
}
