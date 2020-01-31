#include <iostream>
#include <cstring>
#include <iomanip>
#include <cctype>
#include <fstream>

using namespace std;

// named constants
const int MAX_CHAR = 101;
const int MUSIC_LIBRARY_CAP = 100;
const int TITLE = 20;
const int ARTIST = 20;
const int ALBUM = 20;
const int DURATION = 20;

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
void readInEntry(SongEntry& anEntry);
void readInName(char artist[], char album[]);

// DATABASE RELATED FUNCTIONS
void displayAll(const SongEntry list[], int listSize);
void addEntry(const SongEntry& anEntry, SongEntry list[], int& listSize);

// use external file
void loadMusicLibrary(const char fileName[], SongEntry list[], int& listSize);
void saveMusicLibrary(const char fileName[], const SongEntry list[], int listSize);

// Standard input tools
void readString(const char prompt[], char inputStr[], int maxChar);

int main()
{
	char command;
	SongEntry list[MUSIC_LIBRARY_CAP];
	int listSize = 0;
	char fileName[] = "songs.txt";

	loadMusicLibrary(fileName, list, listSize);

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
	cout << "\t3. Search Songs by Artist name" << endl;
	cout << "\t4. Search Songs by Album name" << endl;
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
			readInEntry(entry);
			addEntry(entry, list, listSize);
			break;

		case '2': displayAll(list, listSize);
			break;

		case '3': 
			//readInName(artist);
			break;

		case '4':
			//readInName(album);
			break;

		default: 
			cout << endl << "Wrong Input!" << endl;
			break;
	}
}

//this function reads in a song entry
void readInEntry(SongEntry& anEntry)
{
	char title[MAX_CHAR];
	char artist[MAX_CHAR];
	char duration[MAX_CHAR];
	char album[MAX_CHAR];

	//read input title, artist, duration, album
	readString("Please enter the Title of the song: ", title, MAX_CHAR);
	readString("Please enter the Artist's name: ", artist, MAX_CHAR);
	readString("Please enter the Duration of the song: ", duration, MAX_CHAR);
	readString("Please enter the Album of the song: ", album, MAX_CHAR);

	//populate the pased in object
	strcpy(anEntry.title, title);
	strcpy(anEntry.artist, artist);
	strcpy(anEntry.duration, duration);
	strcpy(anEntry.album, album);
}

void readInName(char artist[], char album[])
{
	readString("Plese enter the Name of the Artist: ", artist, MAX_CHAR);
	readString("Please enter the Name of the Album: ", album, MAX_CHAR);
}

//this function display all songs in file
void displayAll(const SongEntry list[], int listSize)
{
	int index;
	cout << setw(TITLE) << "Title" << setw(ARTIST) << "Artist" << setw(DURATION) << "Duration" << setw(ALBUM) << "Album" << endl;
	for(index = 0; index < listSize; index++)
	{
		cout << setw(TITLE) << list[index].title << setw(ARTIST) << list[index].artist << setw(DURATION) << list[index].duration << setw(ALBUM) << list[index].album << endl;
	}
}

// this function add entry to the end of the file
void addEntry(const SongEntry& anEntry, SongEntry list[], int& listSize)
{
	strcpy(list[listSize].title, anEntry.title);
	strcpy(list[listSize].artist, anEntry.artist);
	strcpy(list[listSize].duration, anEntry.duration);
	strcpy(list[listSize].album, anEntry.album);
	listSize++;
}

// this function searches entries
/*
bool searchEntry(const char artist[], const char album[], SongEntry& match, const SongEntry list[], int lisrSize)
{
	int index;
	for(index = 0; index < listSize; index++)
	{
		if(strcmp(artist, list[index].artist) == 0)
		{
			strcpy(match);
		}
	}
}
*/

//this function load everthing in data file

void loadMusicLibrary(const char fileName[], SongEntry list[], int& listSize)
{
	ifstream in;
	char title[MAX_CHAR];
	char artist[MAX_CHAR];
	char duration[MAX_CHAR];
	char album[MAX_CHAR];
	SongEntry anEntry;

	in.open(fileName);
	if(!in)
	{
		in.clear();
		cerr << endl << "Fail to open " << fileName << " for input!" << endl << endl;
		exit(1);
	}
	in.get(title, MAX_CHAR, ';');
	while(!in.eof())
	{
		in.get();
		in.get(artist, MAX_CHAR, ';');

		in.get();
		in.get(duration, MAX_CHAR, ';');

		in.get();	
		in.get(album, MAX_CHAR, '\n');
		in.ignore(100, '\n');

		strcpy(anEntry.artist, artist);
		strcpy(anEntry.title, title);
		strcpy(anEntry.duration, duration);
		strcpy(anEntry.album, album);

		addEntry(anEntry, list, listSize);

		in.get(title, MAX_CHAR, ';');
	}
	in.close();
}



