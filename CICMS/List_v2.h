#ifndef LIST_V1_
#define LIST_V1_

#include "Product.h"

template <typename T>
class List_v1
{
private:
	struct Node
	{
		T* item;
		Node *next;
		Node::Node(T _item, Node* _next)
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
		delete curr->item;
		delete curr;
	}
}

template <typename T>
bool List_v1<T>::operator=(T &a)
{
	*(_curr->item) = a;
	return true;
}

template <typename T>
T& List_v1<T>::operator[] (int index) 
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
bool List_v1<T>::add(T a)
{
	try
	{
		if(_size==0)
		{
			Node* temp = NULL;
			temp = new Node (a, NULL);
			_head = temp;
			_size++;
			return true;
		}
		else
		{
			Node* temp = NULL;
			temp = new Node (a, _head);
			_head = temp;
			_size++;
			return true;
		}
	}
	catch(std::bad_alloc)
	{
		return false;
	}
}

template <typename T>
bool List_v1<T>::del (T a)
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