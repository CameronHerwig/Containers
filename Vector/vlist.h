
#include <vector>
using namespace std;

#ifndef VLIST_H
#define VLIST_H

class VLIST
{
public:
	VLIST();                //default constructor
	VLIST(const VLIST  &);  //copy constructor
	~VLIST();               //destructor
	bool IsEmpty();         //return true if empty; otherwise false
	void Insert(const string & key); //add key to dynamic array if not full; otherwise prints a message stating dynamic array is full
	void Remove(const string & key); //removes key from dynamic array if it is there; otherwise prints a message stating it was not in dynamic array; the function using an iterator and the erase function to remove an item from the vector.
	void Print(); //Print every string in the array
	vector<string>::iterator VLIST::Search(const string & key);  //returns the location of the string in the dynamic array
	void help();			//prints all commands
private:
	vector<string> DB;  //vector
	int count;
	int capacity;
	//additonal state variables you may wish add
};


#endif
