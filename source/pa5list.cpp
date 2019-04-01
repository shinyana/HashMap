#include <iostream>
#include <string>
#include <cassert>

using namespace std;

#include "listFuncs.h"


int promptForInt(string prompt)
{
	int value;

	cout << prompt << ": ";
	cin >> value;
	return value;
}

string promptForString(string prompt)
{
	string name;

	cout << prompt << ": ";
	cin >> name;
	return name;
}
void printList(ListType list)
{
	//DEBUG

	if (list == NULL)
	{
		cout << "<empty>" << endl;
	}

	ListType p = list;
	while (p != NULL)
	{
		cout << p->key << ":" << p->value << endl;
		p = p->next;
	}
	cout << endl;
}

void emptyCommand(ListType &thelist)
{
	cout << "Remove (Expected:0) : " << flush;
	cout << listRemove(thelist, "Abe") << endl;
	printList(thelist);
		
	cout << "Lookup (Expected: 0) : " << flush;
	cout << listLookup(thelist, "Abe") << endl;
	printList(thelist);

	cout << "Insert (Expected:1) : " << flush;
	cout << listInsert(thelist, "Abe", 100) << endl;
	printList(thelist);
}

void firstListCommand(ListType &thelist)
{
	cout << "Lookup (Expected:100) : " << flush;
	cout << *listLookup(thelist, "Abe") << endl;
	printList(thelist);

	*listLookup(thelist, "Abe") = 120;
	cout << "Change Abe's score to 120" << endl;
	printList(thelist);

	cout << "Lookup (Expected:120) : " << flush;
	cout << *listLookup(thelist, "Abe") << endl;
	printList(thelist);

	cout << "Remove (Expected:0) : " << flush;
	cout << listRemove(thelist, "Kan") << endl;
	printList(thelist);

	cout << "Remove (Expected:1) : " << flush;
	cout << listRemove(thelist, "Abe") << endl;
	printList(thelist);
	
	cout << "Insert (Expected:1) : " << flush;
	cout << listInsert(thelist, "Kan", 50) << endl;
	printList(thelist);
}

void secondListCommand(ListType &thelist)
{
	cout << "Insert (Expected:1) : " << flush;
	cout << listInsert(thelist, "Aso", 70) << endl;
	printList(thelist);

	*listLookup(thelist, "Kan") = 120;
	cout << "Change Kan's score to 120" << endl;
	printList(thelist);

	*listLookup(thelist, "Aso") = 10;
	cout << "Change Aso's score to 10" << endl;
	printList(thelist);

	cout << "Lookup (Expected:120) : " << flush;
	cout << *listLookup(thelist, "Kan") << endl;
	printList(thelist);

	cout << "Lookup (Expected:10) : " << flush;
	cout << *listLookup(thelist, "Aso") << endl;
	printList(thelist);

	cout << "Remove (Expected:1) : " << flush;
	cout << listRemove(thelist, "Kan") << endl;
	printList(thelist);

	cout << "Insert (Expected:1) : " << flush;
	cout << listInsert(thelist, "Tanaka", 60) << endl;
	printList(thelist);

	cout << "Remove (Expected:1) : " << flush;
	cout << listRemove(thelist, "Tanaka") << endl;
	printList(thelist);
	
	cout << "Insert (Expected:1) : " << flush;
	cout << listInsert(thelist, "Morimoto", 45) << endl;
	printList(thelist);

	cout << "Insert (Expected:0) : " << flush;
	cout << listInsert(thelist, "Aso", 5) << endl;
	printList(thelist);
}

void thirdListCommand(ListType &thelist)
{
	cout << "Insert (Expected:1) : " << flush;
	cout << listInsert(thelist, "Nakamura", 95) << endl;
	printList(thelist);

	*listLookup(thelist, "Morimoto") = -50;
	cout << "Change Morimoto's score to -50" << endl;
	printList(thelist);

	cout << "Lookup (Expected:-50) : " << flush;
	cout << *listLookup(thelist, "Morimoto") << endl;
	printList(thelist);

	cout << "Remove (Expected:1) : " << flush;
	cout << listRemove(thelist, "Morimoto") << endl;
	printList(thelist);
}

int main()
{
	char c;
	ListType thelist = NULL;
	
	//command to empty list (r -> c -> l -> i)
	
	emptyCommand(thelist);
	
	//command to 1st list (l -> c -> c -> l -> r -> r -> i)
	
	firstListCommand(thelist);

	//command to 2nd list (i -> c -> c -> l -> l -> r -> i -> r -> i)

	secondListCommand(thelist);

	//command to 3rd list (i -> c -> l -> r -> i)

	thirdListCommand(thelist);

	cout << "press n and newline to finish" << endl;
	cin >> c;
	
	return 0;
}
