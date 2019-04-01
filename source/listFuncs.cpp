#include <iostream>

#include <cassert>

#include "listFuncs.h"

//using namespace std;

Node::Node(const string& theKey, int theValue)
{
	key = theKey;
	value = theValue;
	next = NULL;
}

Node::Node(const string& theKey, int theValue, Node* n)
{
	key = theKey;
	value = theValue;
	next = n;
}


//*************************************************************************
// put the function definitions for your list functions below

// insert name and score in the list
// input	: ListType&, string&, int
// return	: bool
bool listInsert(ListType& list, const string& target, int score)
{
	ListType p = list;

	/* if there is no nodes, add new node in the list */
	if (p == NULL)
	{
		list = new Node(target, score);
		return true;
	}

	/* check whether the name is already present in the list or not */
	while (p != NULL)
	{
		if (target == p->key)
		{
			return false;
		}
		p = p->next;
	}

	/* if there is target name in the list, add new node */
	list = new Node(target, score, list);
	return true;
}

// look for the name and return the corresponding score in the list
// input	: ListType&, string&
// return	: int*
int* listLookup(ListType& list, const string& target)
{
	ListType p = list;

	/* there is no nodes in the list */
	if (p == NULL)
	{
		return NULL;
	}

	/* look for the name which corresponds to target name */
	while (p != NULL)
	{
		if (target == p->key)
		{
			return &(p->value);
		}
		p = p->next;
	}
	return NULL;
}

// remove name and score in the list
// input	: ListType&, string&
// return	: bool
bool listRemove(ListType& list, const string& target)
{
	ListType p = list;
	ListType pp = list; //point to previous address where p points to

	/* there is no nodes in the list */
	if (p == NULL)
	{
		return false;
	}
	/* 1st node should be removed from the list */
	if (target == p->key)
	{
		if (p->next == NULL) //there is only one node in the list
		{
			delete list;
			list = NULL; //point to NULL to avoid exception handling
		}
		else //there are more than one node in the list
		{
			p = list->next;
			delete list;
			list = p;
		}
		return true;
	}
	/* after 2nd node should be removed from the list */
	while (p->next != NULL)
	{
		p = p->next;
		if (target == p->key)
		{
			pp->next = p->next;
			delete p;
			return true;
		}
		pp = pp->next;
	}
	return false;
}
