#include <iostream>
#include <string>
#include "word.h"

using namespace std;

WORD::WORD()
{
	cout << "Inside the default constructor\n";
	front = back = 0;

}

WORD::WORD(const WORD & List)
{
	cout << "Copy Constructor has been invoked\n";
	front = back = 0;
	LIST_NODE *p = List.front;

	while (p != 0)
	{
		Insert(p->data);
		p = p->next;
	}

}

WORD::~WORD()
{
	cout << "Destructor has been called\n";
	while (front != 0)
	{
		LIST_NODE *p = front;
		front = front->next;
		delete p;
	}

}

int WORD::Length(WORD & List)
{
	LIST_NODE *p = List.front;
	int length = 0;
	while (p != 0)
	{
		p = p->next;
		length++;
	}
}

void WORD::Insert(const List_Type & key)
{
	LIST_NODE *p = new LIST_NODE;
	p->data = key;
	p->next = 0;

	if (front == 0)
	{
		front = back = p;
	}
	else if (key <= front->data)
	{
		p->next = front;
		front = p;
	}
	else if (key >= back->data)
	{
		back->next = p;
		back = p;
	}
	else
	{
		LIST_NODE *curr, *prev;



		curr = prev = front;

		cout << "we are here" << curr->data << endl;
		cout << "we are here" << front->data << endl;

		while (curr != 0 && curr->data <= key)
		{
			prev = curr;
			curr = curr->next;
		}

		p->next = curr;
		prev->next = p;
	}

}

//example of overloaded as a member function with chaining
WORD & WORD::operator+(const List_Type & key)
{
	if (front == 0)
	{
		front = new LIST_NODE;
		front->data = key;
		front->next = 0;
		back = front;
	}
	else
	{
		LIST_NODE *p = new LIST_NODE;

		p->data = key;
		p->next = 0;
		back->next = p;
		back = p;
	}
	return *this;
}


//example of overloaded as a friend funciton with chaining
ostream & operator<<(ostream & out, const WORD & List)
{
	LIST_NODE *p = List.front;

	out << endl << endl;

	while (p != 0)
	{
		out << p->data << endl;
		p = p->next;
	}

	return out;
}