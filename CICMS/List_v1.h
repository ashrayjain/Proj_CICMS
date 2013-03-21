#ifndef _list_adt_H_
#define _list_adt_H_

#include <vector>
#include "Product.h"

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
	inline bool isEmpty() { return _database.empty(); }
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
	return _database[idx];
}

#endif