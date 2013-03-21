#ifndef List_v1_
#define List_v1_

#include "Product.h"

template <typename T>
class List_v1
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
	List_v1();

	//destructor
	~List_v1();

	//overload operator[]
	T &operator[](int index);

	//overload operator =
	bool operator=(T &a);

	//add to a specific index
	//in this class will add to the head 
	bool add(T a);

	//remove at a specific index
	bool remove(int index = 0);

	//return the size of the list
	unsigned int size();

		 //return if the function is empty
	 bool isEmpty();

	 //delete a product
	 bool del(T a);


};

template <typename T>
List_v1 <T>::List_v1()
{
	_head = NULL;
	_size=0;
	_curr=_head;
	//_tail=NULL;
	_last=0;
}

template <typename T>
List_v1 <T>::~List_v1()
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
bool List_v1<T>::operator=(T &a)
{
	_curr->item = a;
	return true;
}

template <typename T>
T& List_v1<T>::operator[] (int index) 
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
bool List_v1<T>::add(T a)
{
	if(_size==0||a.getName()<_head->item.getName())
	{
		Node* temp = new Node;
		temp->item = a;
		temp->next = _head;
		_head = temp;
		_size++;
	}
	else
	{
		Node* temp=_head;
		Node* curr = _head;
		Node* temp2 = new Node;
		temp2->item = a;
		while(temp!=NULL&&a.getName()>((temp->item).getName()))
		{
			curr=temp;
			temp=temp->next;
		}
		temp2->next=temp;
		curr->next=temp2;
		_size++;
	}

	return true;

}

//this part we need to take care of _last
template <typename T>
bool List_v1<T>::del (T a)
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
				_size--;
				delete curr;
			}
			else
			{
				Node *curr = temp;
				prev->next = temp->next;
				_size--;
				delete curr;
			}
		}

		prev=temp;
		temp=temp->next;
	}

	return flag;
}


template <typename T>
unsigned int List_v1<T>::size()
{
	return _size;
}

template <typename T>
bool List_v1<T>::isEmpty()
{
	return _size==0;
}

#endif