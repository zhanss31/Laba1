#include "ListSequence.h"
#include <iostream>
using namespace std;

void TestListSequence()
{
	ListSequence <int> a;
	a.Prepend(1);
	a.Prepend(2);
	a.Prepend(4);
	if (a.GetFirst() != 1)
		cout << "First element Error ";
	else cout << "Get Sucess1" << endl;
	if (a.Get(1) != 2)
		cout << "Second element Error ";
	else cout << "Get Sucess2" << endl;
	if (a.GetLast() != 4)
		cout << "Last element Error ";
	else cout << "Get Sucess3" << endl;
	if (a.GetLength() != 3)
		cout << "Length Error ";
	else cout << "Get Sucess4" << endl;
	a.Append(6);
	if (a.GetFirst() != 6)
		cout << "Append Error ";
	else cout << "Get Sucess5" << endl;
	a.InsertAt(2, 8);
	if (a.Get(2) != 8)
		cout << "InsertAt Error ";
	else cout << "Get Sucess6" << endl;
	a.Remove(8);
	if (a.Get(3) == 8)
		cout << "Remove Error ";
	else cout << "Get Sucess7" << endl;
	a.Prepend(5);
	a.Prepend(5);
	a.RemoveAll(5);
	for (int i = 0; i < a.GetLength(); i++)
	{
		if (a.Get(i) == 5)
			cout << "RemoveAll Error ";
		else
		{
			cout << "Get Sucess8" << endl;
			break;
		}

	}
	a.RemoveAt(1);
	if (a.Get(1) == 6)
		cout << "RemoveAt Error ";
	else cout << "Get Sucess9" << endl;


	Sequence <int>* b;
	b = a.GetSubsequence(1, 2);
	if (b->Get(0) != a.Get(1) || b->Get(1) != a.Get(2))
		cout << "GetSubsequence Error!!!";
	else cout << "Get Sucess10" << endl;


	Sequence <int>* c;
	c = a.Concat(b);
	for (int i = 0; i < a.GetLength(); i++)
	{
		if (a.Get(i) != c->Get(i))
			cout << "Concat Error!!!";
	}
	for (int i = 0; i < b->GetLength(); i++)
	{
		if (b->Get(i) != c->Get(i + a.GetLength()))
			cout << "Concat Error!!!";
	}
	cout << "Get Sucess11" << endl;


	Sequence <int>* f;
	f = a.Copy();
	for (int i = 0; i < a.GetLength(); i++)
	{
		if (a.Get(i) != f->Get(i))
			cout << "Concat Error!!!";
	}
	cout << "Get Sucess12" << endl;

	Sequence <int>* d;
	d = a.CopyTo(f, 2);
	for (int i = 0; i < 2; i++)
	{
		if (d->Get(i) != f->Get(i))
			cout << "CopyTo Error";
	}
	for (int i = 0; i < a.GetLength(); i++)
	{
		if (d->Get(i + 2) != a.Get(i))
			cout << "CopyTo Error";
	}
	cout << "Get Sucess13" << endl;
	cout << "Test passed successfully!!!";


}

int main()
{
	setlocale(LC_ALL, "ru");
	TestListSequence();

	return 0;
}
