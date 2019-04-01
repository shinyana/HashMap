// Table.cpp  Table class implementation


#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"
#include <algorithm>


//*************************************************************************

// constructor w/o arguments
Table::Table()
{
	hashSize = HASH_SIZE;
	data = new ListType[HASH_SIZE];
	numEnt = 0;
	numNEBucket = 0;
	for (unsigned int i = 0; i < HASH_SIZE; i++)
	{
		data[i] = NULL;
	}
}

// constructor w/ an argument
Table::Table(unsigned int hSize)
{
	hashSize = hSize;
	data = new ListType[hSize];
	numEnt = 0;
	numNEBucket = 0;
	for (unsigned int i = 0; i < hSize; i++)
	{
		data[i] = NULL;
	}
}

// return an address where a score stores which corresponds to a name
// input	: string&
// return	: int*
int* Table::lookup(const string& key)
{
	return listLookup(data[hashCode(key)], key);
}

// return true if it succeeds to remove a score which corresponds to a name
// input	: string&
// return	: bool
bool Table::remove(const string& key)
{
	if (listRemove(data[hashCode(key)], key))
	{
		numEnt--;
		/* if the bucket becomes empty, count down the number of the non-empty bucket */
		if (data[hashCode(key)] == NULL)
		{
			numNEBucket--;
		}
		return true;
	}
	return false;
}

// return true if it succeeds to insert a score which corresponds to a name
// input	: string&, int
// return	: bool
bool Table::insert(const string& key, int value)
{
	/* if the bucket becomes not empty, count up the number of the non-empty bucket*/
	if (data[hashCode(key)] == NULL)
	{
		numNEBucket++;
	}

	if (listInsert(data[hashCode(key)], key, value))
	{
		numEnt++;
		return true;
	}
	return false;
}

// return the number of entries
// input	: N/A
// return	: int
int Table::numEntries() const
{
	return numEnt;
}

// print out values and key
// input	: N/A
// return	: N/A
void Table::printAll() const
{
	/* if the longest chain is zero, it means the map is empty */
	if (mapTraverse(true) == 0)
	{
		cout << " <Empty> " << endl;
	}
}

// print out statictis about the hash table
// input	: ostream&
// return	: N/A
void Table::hashStats(ostream& out) const
{
	cout << "number of buckets: " << hashSize << endl;
	cout << "number of entries: " << numEnt << endl;
	cout << "number of non-empty buckets: " << numNEBucket << endl;
	cout << "longest chain: " << mapTraverse(false) << endl;
}


// add definitions for your private methods here

// traverse in the array and linked list.
// return the number of longest chain in the array
// if bool is true and there are entries, print out all entries.
// input	: bool
// return	: int
int Table::mapTraverse(bool printON) const
{
	ListType p;
	int longNumChain = 0;

	for (unsigned int i = 0; i < hashSize; i++)
	{
		int countChain = 0;
		p = data[i];

		while (p != NULL)
		{
			/* print out an entry */
			if (printON)
			{
				cout << p->key << " : " << p->value << endl;
			}

			countChain++;
			p = p->next;
		}
		/* compare the longest chain to new one */
		longNumChain = max(longNumChain, countChain);
	}
	return longNumChain;
}
