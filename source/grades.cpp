/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 * 
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default size (Table::HASH_SIZE)
 *
 */

#include "Table.h"
//#include <iostream>

// cstdlib needed for call to atoi
#include <cstdlib>

//show messages when command error occurred or ask help
void showCommand()
{
	cout << "insert name score: Insert the name and her/his score in the grade table." << endl;
	cout << "change name score: Change the name's score in the grade table." << endl;
	cout << "lookup name: Lookup the name and print out the name and her/his score in the grade table." << endl;
	cout << "remove name: Remove the name in the grade table." << endl;
	cout << "print: Print out all names and scores in the grade table." << endl;
	cout << "size: Print out the number of entries in the grade table." << endl;
	cout << "stats: Print out statistics about the grade table." << endl;
	cout << "help: Print out a brief of command summary." << endl;
	cout << "quit: Exits the program." << endl;
}

//check whether input is value(integer) or not
//input		:none 
//return	:int
int errorCheck()
{
	int score = 0;
	cin >> score;

	while (!cin)
	{
		/* remove error flug */
		cin.clear();
		/* delete buffer until finding newline */
		cin.ignore(INT_MAX, '\n');
		cout << "ERROR: invalid score" << endl;
		cout << "input score>";
		cin >> score;
	}
	return score;
}

//call insert function
//input		:Table*
//return	:void
void callInsert(Table* grades)
{
	string name;

	cin >> name;
	const int score = errorCheck();

	if (!grades->insert(name, score)) //fail
	{
		cout << "This name is already present." << endl;
	}
}

//call lookup function then change the score
//input		:Table*
//return	:void
void callChange(Table* grades)
{
	string name;

	cin >> name;
	const int score = errorCheck();

	if (grades->lookup(name) == NULL) //fail
	{
		cout << "This name is not present." << endl;
	}
	else //success
	{
		*grades->lookup(name) = score;
	}
}

//call lookup function
//input		:Table*
//return	:void
void callLookup(Table* grades)
{
	string name;

	cin >> name;

	if (grades->lookup(name) == NULL) //fail
	{
		cout << "This name is not present." << endl;
	}
	else //success
	{
		cout << name << ": " << *grades->lookup(name) << endl;
	}
}

//call remove function
//input		:Table*
//return	:void
void callRemove(Table* grades)
{
	string name;

	cin >> name;

	if (!grades->remove(name)) //fail
	{
		cout << "This name is not present." << endl;
	}
}

//start to input command
//input		:Table*
//return	:void
void simulation(Table* grades)
{
	bool keepgoing = true;
	string cmd;

	do
	{
		cout << "cmd>" << flush;
		cin >> cmd;

		if (cmd == "insert")
		{
			callInsert(grades);
		}
		else if (cmd == "change")
		{
			callChange(grades);
		}
		else if (cmd == "lookup")
		{
			callLookup(grades);
		}
		else if (cmd == "remove")
		{
			callRemove(grades);
		}
		else if (cmd == "print")
		{
			grades->printAll();
		}
		else if (cmd == "size")
		{
			cout << "The number of entries : " << grades->numEntries() << endl;
		}
		else if (cmd == "stats")
		{
			grades->hashStats(cout);
		}
		else if (cmd == "help")
		{
			showCommand();
		}
		else if (cmd == "quit")
		{
			keepgoing = false;
		}
		else
		{
			cout << "ERROR: invalid command" << endl;
			showCommand();
		}
	}
	while (keepgoing);
}

//main function. define hashsize before running simulation 
//input		:command line
//return	:int
int main(int argc, char* argv[])
{
	// gets the hash table size from the command line

	int hashSize = Table::HASH_SIZE;

	Table* grades; // Table is dynamically allocated below, so we can call
	// different constructors depending on input from the user.

	if (argc > 1)
	{
		hashSize = atoi(argv[1]); // atoi converts c-string to int

		if (hashSize < 1)
		{
			cout << "Command line argument (hashSize) must be a positive number"
				<< endl;
			return 1;
		}

		grades = new Table(hashSize);
	}
	else
	{
		// no command line args given -- use default table size
		grades = new Table();
	}


	grades->hashStats(cout);

	// add more code here
	// Reminder: use -> when calling Table methods, since grades is type Table*

	simulation(grades);

	return 0;
}
