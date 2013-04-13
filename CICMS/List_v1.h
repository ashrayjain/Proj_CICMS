/*************************************************************************************************/
//
//  class list_adt: List_v1.h 
//	Version 1
//
//  Description: list_adt v1 implements class list_adt using an STL vector as the basis for storing
//  the data. It has been made compatible with all data types (user-defined or otherwise) using
//  templates. The class provides basic functionality like addition and deletion from the list.
//  It also provides access to elements by their index in the list by overloading the array 
//  subscript operator [].
//
//  API:
//  bool add(T newItem);
//	bool del(T delItem);
//	T& operator[](int idx);
//	unsigned size();
//	bool isempty();
//
//  Main authors: ASHRAY JAIN (A0105199B)
//
/*************************************************************************************************/



#ifndef _list_adt_H_
#define _list_adt_H_

#include "stdafx.h"
#include <vector>

using namespace std;

template <class T>
class list_adt
{
private:
	vector<T> _database;
public:
	bool add(T newItem);
	bool del(T delItem);
	T& operator[](int idx);
	inline unsigned size() { return _database.size(); }
	inline bool isempty() { return _database.empty(); }
};

template <class T>
bool list_adt<T>::add(T newItem)
{
	try
	{
		_database.push_back(newItem);
		return true;
	}
	catch(bad_alloc)
	{
		return false;
	}
}

template <class T>
bool list_adt<T>::del(T delItem)
{
	int delidx = -1;
	for(unsigned i = 0; i < _database.size(); i++)
		if(_database[i] == delItem)
			delidx = i;
	if(delidx == -1)
		return false;
	_database.erase(_database.begin()+delidx);
	return true;
}

template <class T>
T& list_adt<T>::operator[](int idx)
{
	return _database.at(idx);
}

#endif