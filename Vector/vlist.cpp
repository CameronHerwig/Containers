
#include <iostream>
#include <vector>
#include <string>
#include "VLIST.h"
#include <algorithm>

using namespace std;

VLIST::VLIST(){
	cout << "The Default Constructor Invoked!" << endl << endl;
	count = 0;
	capacity = 9;
	DB = {};
}



VLIST::VLIST(const VLIST & Org){
	cout << "Copy Constructor Invoked!" << endl << endl;
	count = Org.count;
	capacity = Org.capacity;
	vector <string> temp = {};
	for(int i = 0; i < count; i++)
	{
		temp.push_back(Org.DB[i]);
	}
	DB = temp;
}


VLIST::~VLIST(){
	cout << "The Destructor has been Invoked." << endl;
	for (int i = count; i < 0; i--)
	{
		DB.pop_back();
	}
	count = 0;
	capacity = 0;
}

bool VLIST::IsEmpty()
{   
	cout << "IsEmpty has been Invoked." << endl;
	if (count == 0)
	{
		return true;

	}
	else
	{
		return false;
	}
}


void VLIST::Insert(const string & key){
	cout << "Insert Invoked. (" << key << ")" << endl;
	cout << "Before: ";
	Print();
	DB.push_back(key);
	count++;
	sort(DB.begin(), DB.end());
	cout << "After:  ";
	Print();
	cout << endl;
}


void VLIST::Remove(const string & key){
	cout << "Remove Invoked. (" << key << ")" << endl;
	cout << "Before: ";
	Print();
	cout << "Search Invoked. (" << key << ")" << endl;
	if (Search(key) != DB.end())
	{
		cout << "Item Found!" << endl;
		DB.erase(Search(key));
		count--;
	}
	cout << "After:  ";
	Print();
	cout << endl;
}


vector<string>::iterator VLIST::Search(const string & key)
{
	string check = key;
	vector<string>::iterator it;
	//cout << "Search Invoked. (" << key << ")" << endl;			This prevents double printing due to repeat call for null check
	for (it = DB.begin(); it != DB.end(); it++)
	{
		if (*it == check)
		{
			//cout << "Item Found!" << endl;						This prevents double printing due to repeat call for null check
			return it;
		}
	}
	cout << "Item Not Found!" << endl;
	return it;
}


void VLIST::Print()
{
	for (int i = 0; i < count; i++)
	{
		cout << " " << DB[i] << " ";
	}
	cout << endl;
}

void VLIST::help()
{
	cout << "Default Constructor:   VLIST 'name';" << endl;
	cout << "Copy Constructor:      VLIST 'name' = 'ObjName';" << endl;
	cout << "Is Empty:              obj.Is_Empty();" << endl;
	cout << "Insert:                obj.Insert('Text');" << endl;
	cout << "Remove:                obj.Remove('Text');" << endl;
	cout << "Print:                 obj.Print();;" << endl;
}