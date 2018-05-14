#include <iostream>
#include <string>

using namespace std;

#ifndef SLIST_H
#define SLIST_H

typedef string List_Type;
//declaration for a node in the list
class LIST_NODE
{
public:
	List_Type data; //data element
	LIST_NODE *next; //pointer element
};

//declaration of a list class
class WORD
{
public:
	WORD();//default constructor
	WORD(const WORD & List);
	~WORD();
	void Insert(const List_Type & key);
	int Length(WORD & List);
	bool Is_Empty(){ return front == 0; }; //accessor
	WORD & operator+(const List_Type &);
	friend ostream & operator<<(ostream &, const WORD &);
private:

	LIST_NODE *front, *back;

};

WORD & operator-(WORD & List, const List_Type & item);

#endif