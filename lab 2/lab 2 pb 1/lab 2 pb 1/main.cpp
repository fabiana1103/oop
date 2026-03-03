#include <iostream>
#include "NumberList.h"

NumberList mylist;

int main()
{
	mylist.Init();
	mylist.Add(5);
	mylist.Add(7);
	mylist.Add(13);
	mylist.Add(21);
	mylist.Add(4);
	mylist.Sort();
	mylist.Print();
}