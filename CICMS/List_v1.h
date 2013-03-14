#ifndef _LIST_V1_H_
#define _LIST_V1_H_

#include <vector>
#include "Product.h"

using namespace std;

template <class T>
class List_v1
{
private:
	vector<T> _database;
public:
	List_v1(){}
	bool add(T newItem);
	bool del(T delItem);
	T& operator[](int idx);
	inline unsigned size() { 
		return _database.size(); }
	inline bool isEmpty() { return _database.empty(); }
};

template <class T>
bool List_v1<T>::add(T newItem)
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
bool List_v1<T>::del(T delItem)
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
T& List_v1<T>::operator[](int idx)
{
	return _database[idx];
}

#endif