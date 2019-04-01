//*************************************************************************
// Node class definition 
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// because it's used by the Table class; not by any Table client code.


#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H
#include <string>

using namespace std;

struct Node
{
	string key;
	int value;

	Node* next;

	Node(const string& theKey, int theValue);

	Node(const string& theKey, int theValue, Node* n);
};


typedef Node* ListType;

//*************************************************************************
//add function headers (aka, function prototypes) for your functions
//that operate on a list here (i.e., each includes a parameter of type
//ListType or ListType&).  No function definitions go in this file.

bool listInsert(ListType& list, const string& target, int score);
int* listLookup(ListType& list, const string& target);
bool listRemove(ListType& list, const string& target);

// keep the following line at the end of the file
#endif
