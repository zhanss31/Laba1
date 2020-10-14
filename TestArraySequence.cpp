#include "ArraySequence.h"
#include <iostream>
using namespace std;

int main()
{
	ArraySequence <int> a;
	a.Append(2);
	a.Append(3);
	a.Append(4);
	if (a.GetFirst() != 4)
		cout << "First element Error ";
	else cout << "Get Sucess1" << endl;
	if (a.Get(1) != 3)
		cout << "Second element Error ";
	else cout << "Get Sucess2" << endl;
	if (a.GetLast() != 2)
		cout << "Last element Error ";
	else cout << "Get Sucess3" << endl;
	if (a.GetLength() != 3)
		cout << "Length Error ";
	else cout << "Get Sucess4" << endl;

	a.InsertAt(2, 8);
	if (a.Get(2) != 8)
		cout << "InsertAt Error ";
	else cout << "Get Sucess5" << endl;


	a.Prepend(6);
	if (a.GetLast() != 6)
		cout << "Prepend Error ";
	else cout << "Get Sucess6" << endl;


	a.RemoveAt(3);
	if (a.Get(3) == 2)
		cout << "RemoveAt Error ";
	else cout << "Get Sucess7" << endl;

	a.Remove(8);
	if (a.Get(2) == 8)
		cout << "Remove Error ";
	else cout << "Get Sucess8" << endl;

	a.Prepend(6);
	a.RemoveAll(6);
	for (int i = 0; i < a.GetLength(); i++)
	{
		if (a.Get(i) == 6)
			cout << "RemoveAll Error";
	}
	cout << "Get Sucess9" << endl;

	a.Prepend(1);
	a.Prepend(2);
	a.Prepend(3);
	Sequence <int>* c;
	c = a.GetSubsequence(0, 2);
	if (c->Get(0) != a.Get(0) || c->Get(1) != a.Get(1) || c->Get(2) != a.Get(2))
		cout << "GetSubsequence Error";
	else cout << "Get Sucess10" << endl;

	Sequence <int>* b;
	b = a.Concat(c);
	for (int i = 0; i < a.GetLength(); i++)
	{
		if (b->Get(i) != a.Get(i))
			cout << "Concat Error";
	}
	for (int i = 0; i < c->GetLength(); i++)
	{
		if (b->Get(i + a.GetLength()) != c->Get(i))
			cout << "Concat Error";
	}
	cout << "Get Sucess11" << endl;
	Sequence <int>* q;
	q = a.Copy();
	for (int i = 0; i < a.GetLength(); i++)
	{
		if (q->Get(i) != a.Get(i))
			cout << "Copy Error";
	}
	cout << "Get Sucess12" << endl;

	Sequence <int>* d;
	d = a.CopyTo(q, 2);
	for (int i = 0; i < 2; i++)
	{
		if (d->Get(i) != q->Get(i))
			cout << "CopyTo Error";
	}
	for (int i = 0; i < a.GetLength(); i++)
	{
		if (d->Get(i + 2) != a.Get(i))
			cout << "CopyTo Error";
	}
	cout << "Get Sucess13" << endl;

	

	cout << "Test passed successfully!!!";
	return 0;
}
