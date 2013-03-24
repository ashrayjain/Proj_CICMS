/*************************************************************************************************/
//
//  class list_adt : version 3
//
//  Description: Sorted linked list.
//
//  API:
//  bool add(T newItem);
//	bool del(T delItem);
//	T& operator[](int idx);
//	unsigned size();
//	bool isempty();
//
//  Main authors: HUI HUI(A0105566E)
//
/*************************************************************************************************/

#ifndef _list_adt_H_
#define _list_adt_H_

#include "stdafx.h"

template <typename T>
class list_adt
{
private:
	struct Node
	{
		T* item;
		Node *next;
		Node(T _item, Node* _next)
		{
			item = new T(_item);
			next = _next;
		}

	};

	Node* _head;
	Node* _curr;

	int _size;
	int _last;

public:

	//constructor
	list_adt();

	//destructor
	~list_adt();

	//overload operator[]
	T &operator[](int index);

	//overload operator =
	bool operator=(T &a);

	//add to a specific index in accending order
	bool add(T a);

	//return the size of the list
	unsigned int size();

	//return if the function is empty
	bool isempty();

	//delete a product
	bool del(T a);
};

template <typename T>
list_adt <T>::list_adt()
{
	_head = NULL;
	_size=0;
	_curr=_head;
	_last=0;
}

template <typename T>
list_adt <T>::~list_adt()
{
	while(_head!=NULL)
	{
		Node *curr;
		curr = _head;
		_head = _head->next;
		delete curr->item;
		delete curr;
	}
}

template <typename T>
bool list_adt<T>::operator=(T &a)
{
	*(_curr->item) = a;
	return true;
}

template <typename T>
T& list_adt<T>::operator[] (int index) 
{
	if(_curr!=NULL)
	{
		if(index == _last)
		{
			return *(_curr->item);
		}
		else if(index>_last)
		{
			for(int i=0;i<(index-_last);i++)
				_curr=_curr->next;
			_last=index;
			return *(_curr->item);
		}
		else
		{
			Node* temp = _head;
			for(int i=0;i<index;i++)
				temp=temp->next;
			_last=index;
			_curr=temp;
			return *(temp->item);
		}
	}
	else
	{
		Node* temp = _head;
		for(int i=0;i<index;i++)
			temp=temp->next;
		_last=index;
		_curr=temp;
		return *(temp->item);
	}
}

//It will always insert to the head of the list
template <typename T>
bool list_adt<T>::add(T a)
{
	try
	{
		if(_size==0)
		{
			Node* temp = NULL;
			temp = new Node (a, NULL);
			_head = temp;
			_size++;
			_curr=_head;
			_last=0;
		}
		else if(a<=*(_head->item))
		{

			Node* temp = NULL;
			temp = new Node (a, _head);
			_head = temp;
			_size++;
			_curr=_head;
			_last=0;
		}
		else
		{
			Node* temp=_head;
			Node* curr = _head;
			Node* temp2 = NULL;
			temp2 = new Node (a, NULL);
			while(temp!=NULL&&(a>*(temp->item)))
			{
				curr=temp;
				temp=temp->next;
			}
			temp2->next=temp;
			curr->next=temp2;
			_size++;
			_curr=_head;
			_last=0;
		}

		return true;
	}
	catch(std::bad_alloc)
	{
		return false;
	}
}

template <typename T>
bool list_adt<T>::del (T a)
{
	bool flag = false;
	Node *temp=_head;
	Node *prev=NULL;

	while(!flag&&temp!=NULL)
	{
		if(*(temp->item) == a)
		{
			flag = true;
			if(prev==NULL)
			{
				Node *curr = _head;
				_head=_head->next;
				_size--;
				delete curr->item;
				delete curr;
			}
			else
			{
				Node *curr = temp;
				prev->next = temp->next;
				_size--;
				delete curr->item;
				delete curr;
			}
		}

		prev=temp;
		temp=temp->next;
	}
	_curr=_head;
	_last=0;
	return flag;
}

template <typename T>
unsigned int list_adt<T>::size()
{
	return _size;
}

template <typename T>
bool list_adt<T>::isempty()
{
	return _size==0;
}

#endif