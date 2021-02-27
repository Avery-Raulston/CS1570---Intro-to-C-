///////////////////////////
//@file hw4.cpp
//@author Avery Raulston CS1570
//@brief character to morse-code/ascii value translator
///////////////////////////

#include<iostream>
#include<cstdlib>
using namespace std;

//Description: Presents the menu to the user and reads in valid menu choice
//Pre: None
//Post: Menu is presented to the user and a valid menu choice is returned
short present_menu();

//Description: Prompts for and reads in a valid alphabetic character
//Pre: None
//Post: Valid alphabetic character has been inputted by the user
char enter_character();

//Description: Displays morse code equivalent of character parameter
//Pre: Character parameter must be alphabetic
//Post: Morse code equivalent of character parameter will be outputted to screen
void morse_code_translator(const char character);

//Description: Displays ASCII equivalent of character parameter
//Pre: Character parameter must be alphabetic
//Post: ASCII value equivalent of character parameter will be outputted to screen
void ascii_translator(const char character);

//Description: Displays a random secret message and the morse code equivalent to  
//		the user. The secret message will be three words. The first word 
//		will be 4 letters, the second word will be 3 letters, and the 
//		third word will be four letters
//Pre: None
//Post: Randomly generated message will be outputted to the screen, along with 
//	 the morse code equivalent of the message
void display_secret_message();
	
// Constants
const short ENTER_CHARACTER = 1;
const short MORSE_CODE = 2;
const short ASCII = 3;
const short SECRET_MESSAGE = 4;
const short QUIT = 5;
const short LENGTH_ALPHABET = 26;
const short MIN_ASCII_UPPERCASE_VALUE = 65;
const short MAX_ASCII_UPPERCASE_VALUE = 90;
const short MIN_ASCII_LOWERCASE_VALUE = 97;
const short MAX_ASCII_LOWERCASE_VALUE = 122;

int main()
{
	srand(time(NULL));
// Variables
	short option;
 	char character;
	bool quit = false;
	bool is_option1_chosen = false;

// Greetings
	cout<<"TRANSLATE"<<endl;
	cout<<"---------"<<endl;

// Logic and Output
	do 
	{
		option = present_menu();
		
		switch (option)
		{
			case ENTER_CHARACTER:
				character = enter_character();
				is_option1_chosen = true;
				break;
			case MORSE_CODE:
				if (is_option1_chosen)
				{
					cout<<character<<" in morse code is: ";
					morse_code_translator(character);
				}
				else
					cout<<"Error: You must choose option 1 before you can choose this option"<<endl;
				break;
			case ASCII:
				if (is_option1_chosen)
					ascii_translator(character);
				else
					cout<<"Error: You must choose option 1 before you can choose this option"<<endl;
				break;
			case SECRET_MESSAGE:
				display_secret_message();
				break;
			case QUIT:
				quit = true;

		}
	}	while (! quit);

// Signing off Statement
	cout<<"Goodbye!"<<endl;
	return 0;
}

short present_menu()
{
	short option;
	do
	{
		cout<<endl<<"1. Enter a character (alphabetic)"<<endl;
		cout<<"2. Morse code equivalent"<<endl;
		cout<<"3. ASCII value"<<endl;
		cout<<"4. Secret Message"<<endl;
		cout<<"5. Kwit"<<endl<<endl;
		cout<<"Choice: ";
		cin>>option;
		if (option < 1 || option > 5)
			cout<<"Invalid choice"<<endl<<endl;
	}	while (option < 1 || option > 5);
	return option;	
}

char enter_character()
{
	char character;
	do
	{
		cout<<"Please enter an alphabetic character: ";
		cin>>character;;
		if ((int(character) < MIN_ASCII_UPPERCASE_VALUE || int(character) > MAX_ASCII_UPPERCASE_VALUE) && (int(character) < MIN_ASCII_LOWERCASE_VALUE || int(character) > MAX_ASCII_UPPERCASE_VALUE))
			cout<<endl<<"Error: You did not enter an alphabetic character"<<endl;
	} while ((int(character) < 65 || int(character) > 90) && (int(character) < 97 || int(character) > 122));
	return character;
}

void morse_code_translator(const char character)
{
	switch (character)
	{
		case 'a': case 'A':
			cout<<".-"<<endl;
			break;
		case 'b': case 'B':
			cout<<"-..."<<endl;
			break;
		case 'c': case 'C':
			cout<<"-.-."<<endl;
			break;
		case 'd': case 'D':
			cout<<"-.."<<endl;
			break;
		case 'e': case 'E':
			cout<<"."<<endl;
			break;
		case 'f': case 'F':
			cout<<"..-."<<endl;
			break;
		case 'g': case 'G':
			cout<<"--."<<endl;
			break;
		case 'h': case 'H':
			cout<<"...."<<endl;
			break;
		case 'i': case 'I':
			cout<<".."<<endl;
			break;
		case 'j': case 'J':
			cout<<".---"<<endl;
			break;
		case 'k': case 'K':
			cout<<"-.-"<<endl;
			break;
		case 'l': case 'L':
			cout<<".-.."<<endl;
			break;
		case 'm': case 'M':
			cout<<"--"<<endl;
			break;
		case 'n': case 'N':
			cout<<"-."<<endl;
			break;
		case 'o': case 'O':
			cout<<"---"<<endl;
			break;
		case 'p': case 'P':
			cout<<".--."<<endl;
			break;
		case 'q': case 'Q':
			cout<<"--.-"<<endl;
			break;
		case 'r': case 'R':
			cout<<".-."<<endl;
			break;
		case 's': case 'S':
			cout<<"..."<<endl;
			break;
		case 't': case 'T':
			cout<<"-"<<endl;
			break;
		case 'u': case 'U':
			cout<<"..-"<<endl;
			break;
		case 'v': case 'V':
			cout<<"...-"<<endl;
			break;
		case 'w': case 'W':
			cout<<".--"<<endl;
			break;
		case 'x': case 'X':
			cout<<"-..-"<<endl;
			break;
		case 'y': case 'Y':
			cout<<"-.--"<<endl;
			break;
		case 'z': case 'Z':
			cout<<"--.."<<endl;
	}
	return;
}

void ascii_translator(const char character)
{
	cout<<"The ASCII equivalent of your character is: "<<int(character)<<endl;
	return;
}

void display_secret_message()
{
	short ascii_value;
	char character;
	cout<<endl;
	for (int i = 1; i < 12; i++)
	{
		ascii_value = (rand() % LENGTH_ALPHABET) + MIN_ASCII_LOWERCASE_VALUE;
		character = char(ascii_value);
		cout<<character<<"    ";
		morse_code_translator(character);
		if ((i == 4) || (i == 7))
			cout<<endl;
	}
	return;
}

