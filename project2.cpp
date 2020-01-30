#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

// named constants
const int MAX_CHAR = 101;


// define a new data type 
struct SongEntry
{
	char title[MAX_CHAR];
	char artist[MAX_CHAR];
	char duration[MAX_CHAR];
	char album[MAX_CHAR];
};

// USER INTERFACE RELATED FUNCTIONS
void displayMenu();

// DATABASE RELATED FUNCTIONS

// Standard input tools
void readString(const char prompt[], char inputStr[], int maxChar);

int main()
{
	displayMenu();
	return 0;
}

// this function reads a c-string from standard input
void readString(const char prompt[], char inputStr[], int maxChar)
{
	cout << endl << prompt;

	//read until it reach maxChar limit or encounters a '\n'
	cin.get(inputStr, maxChar, '\n');
	while(!cin)
	{
		cin.clear();
		cin.ignore(100, '\n');
		cout << endl << prompt;
		cin.get(inputStr, maxChar, '\n')
	}
	//throw away the '\n'
	cin.ignore(100, '\n');
}

// This function displays the main menu.
void displayMenu()
{
	cout << endl << "Welcome to your music library!" << endl << endl;
	cout << "\t1. Add an entry" << endl;
			<< "\t2. List all entries" << endl;
			<< "\t3: Search a Song by name" << endl;
			<< "\tq: Exit this program" << endl << endl;
}

