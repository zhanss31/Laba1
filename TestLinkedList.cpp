#include "LinkedList.h"
int main()
{

	setlocale(LC_ALL, "ru");


	LinkedList<int> lst;
	lst.append(5);
	lst.append(7);
	lst.append(101);

	LinkedList<int> lst2;
	lst2.append(6);
	lst2.append(8);
	lst2.append(102);
	for (int i = 0; i < lst.Getlength(); i++)
	{
		cout << lst[i] << endl;
	}
	cout << "new list" << endl;
	LinkedList<int> Concatlists;
	Concatlists = *lst.Concat(&lst2);
	for (int i = 0; i < Concatlists.Getlength(); i++)
	{
		cout << Concatlists[i] << endl;
	}
	cout << endl << "prepend " << endl << endl;
	lst.prepend(6);

	for (int i = 0; i < lst.Getlength(); i++)
	{
		cout << lst.Get(i) << endl;
	}

	return 0;
}
