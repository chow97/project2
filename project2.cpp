//use character arrays and <cstirng>
//use struct to model composite data tyoe
//file input/output
//use array of objects to model a collection
//master pass by reference or pass by value

/*
You are asked to write an app to keep track of relatively small music library.
The app should load song information from a data file once the app is started. 
It should allow user to view, add, remove and search for songs. 
The app should save the data back to the same data file when the program exits.
*/

/*
Write an interactive text based menu interface (using a loop) that will allow the user to 

	Enter information for a new song.
	Display information for all the songs in the database with index for each song
	Remove a song by index
	Search forsongs by certain artist
	Search for songs by a certain album
	Quit
*/

/*
For each song, you need to keep track of:

	Title
	Artist
	duration
	album

Allow the program to keep looping until user wants to quit. 
When the program starts, it should load the tasks from external file ("songs.txt") into memory.
When user enters information about the new song, the program needs to read them in, save them in memory and eventually write them to external data file("songs.txt").
The file format could look like:
Stereo Hearts;Gym Class Heroes;3;34;The Papercut Chronicles II 
Counting stars; OneRepublic;4;17;Native

use ; as delimiter or field separator.
*/

// Write at least 4 founctions with args
// Use struct named Sing to model each song
// Use array of structs to model the collection of songs
// Hint: Read using the 3 argument version of get.
// Watch out. When using the 3 argument version of get you need to make sure to remove the delimeter or newline.            Therefore, anytime you read (even confirmation message) make sure to eat the new line using cin.ignore(...)
// Make sure to have a delimiter written between each item in the file. -- like a new line
// this will be important when you read the information back from the file.

/*
For submission your data file should contain a sufficient set of data
It should have test cases for same artist with multiple songs and same album with multiple songs in it
*/
#include <iostream>
#include <cstring>


