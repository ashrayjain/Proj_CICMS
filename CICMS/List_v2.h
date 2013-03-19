#ifndef LIST_V2_
#define LIST_V2_

#include "Product.h"

template <typename T>
class list_adt
{
private:
	struct Node
	{
		T item;
		Node *next;
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

	//add to a specific index
	//in this class will add to the head 
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
	//_tail=NULL;
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
		delete curr;
	}
}

template <typename T>
bool list_adt<T>::operator=(T &a)
{
	_curr->item = a;
	return true;
}

template <typename T>
T& list_adt<T>::operator[] (int index) 
{
	if(_curr!=NULL)
	{
		if(index == _last)
		{
			return _curr->item;
		}
		else if(index>_last)
		{
			for(int i=0;i<(index-_last);i++)
			{
				_curr=_curr->next;
				_last=index;
				return _curr->item;
			}
		}
		else
		{
			Node* temp = _head;
			for(int i=0;i<index;i++)
				temp=temp->next;
			_last=index;
			_curr=temp;
			return temp->item;
		}
	}
	else
	{
		Node* temp = _head;
		for(int i=0;i<index;i++)
			temp=temp->next;
		_last=index;
		_curr=temp;
		return temp->item;
	}
}

//It will always insert to the head of the list
template <typename T>
bool list_adt<T>::add(T a)
{
	try
	{
	Node* temp = new Node;
	temp->item = a;
	temp->next = _head;
	_head = temp;
	_size++;
	return true;
	}
	catch(std::bad_alloc)
	{
		return false;
	}
}

//this part we need to take care of _last
template <typename T>
bool list_adt<T>::del (T a)
{
	bool flag = false;
	Node *temp=_head;
	Node *prev=NULL;
	while(temp!=NULL&&!flag)
	{
		if(temp->item == a)
		{
			flag = true;
			if(temp==_head)
			{
				Node *curr = _head;
				_head=_head->next;
				delete curr;
			}
			else
			{
				Node *curr = temp;
				prev->next = temp->next;
				delete curr;
			}
		}

		prev=temp;
		temp=temp->next;
	}

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