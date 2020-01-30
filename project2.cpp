#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

// named constants
const int MAX_CHAR = 101;
const int MUSIC_LIBRARY_CAP = 100;

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
char readInCommand();
void processCommand(char command, SongEntry list[], int& listSize);

// DATABASE RELATED FUNCTIONS

// Standard input tools
void readString(const char prompt[], char inputStr[], int maxChar);

int main()
{
	char command;
	SongEntry list[MUSIC_LIBRARY_CAP];
	int listSize = 0;
	
	displayMenu();
	command = readInCommand();
	while (command != 'q')
	{
		processCommand(command, list, listSize);
		displayMenu();
		command = readInCommand();
	}
	cout << endl <<  "Thank you" << endl << endl;

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
		cin.get(inputStr, maxChar, '\n');
	}
	//throw away the '\n'
	cin.ignore(100, '\n');
}

// This function displays the main menu.
void displayMenu()
{
	cout << endl << "Welcome to your music library!" << endl << endl;
	cout << "Choose from the following options: " << endl;
	cout << "\t1. Add an entry" << endl;
	cout << "\t2. List all entries" << endl;
	cout << "\t3. Search a Song by name" << endl;
	cout << "\tq. Exit this program" << endl << endl;
}

char readInCommand()
{
	char cmd;

	cout << endl << "Please enter command(1, 2, 3 or q): ";
	cin >> cmd;
	cin.ignore(100, '\n');
	return tolower(cmd);
}

void processCommand(char command, SongEntry list[], int& listSize)
{
	SongEntry entry;
	char title[MAX_CHAR];

	switch(command)
	{
		case '1': 
			//readInEntry(entry);
			//addEntry(entry, list, listSize);
			break;
		case '2': 
			//displayAll(list listSize);
			break;
		case '3': 
			//readInName(name);
			break;
		default: 
			cout << endl << "Wrong Input!" << endl;
			break;
	}
}


