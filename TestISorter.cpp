#include "ISorter.h"
#include <iostream>
using namespace std;

int main()
{
	int x;
	cout << "ListSequence -1; ArraySequence-2";
	int r;
	cin >> r;
	switch (r)
	{
	case 1:
	{
		ListSequence <int> a;
		a.Append(4);
		a.Append(2);
		a.Append(1);
		a.Append(6);
		Sequence <int>* q;
		q = a.Copy();
		InsertSorter<int> b{};
		b.Sort(*q);
		cout << "\n";
		for (int x = 1; x < q->GetLength(); x++)
		{
			if (q->Get(x - 1) > q->Get(x))
			{
				cout << "Fail!" << endl;
				break;
			}
		}
		cout << "success 1" << endl;
		Sequence <int>* y;
		y = a.Copy();
		BubbleSorter<int> z{};
		z.Sort(*y);
		for (int x = 1; x < y->GetLength(); x++)
		{
			if (y->Get(x - 1) > y->Get(x))
			{
				cout << "Fail!" << endl;
				break;
			}
		}
		cout << "success 2" << endl;

		Sequence <int>* h;
		h = a.Copy();
		ShellSorter<int> u{};
		u.Sort(*h);
		for (int x = 1; x < h->GetLength(); x++)
		{
			if (h->Get(x - 1) > h->Get(x))
			{
				cout << "Fail!" << endl;
				break;
			}
		}
		cout << "success 3" << endl;

		Sequence <int>* j;
		j = a.Copy();
		PyramidSorter<int> l{};
		l.Sort(*j);
		for (int x = 1; x < j->GetLength(); x++)
		{
			if (j->Get(x - 1) > j->Get(x))
			{
				cout << "Fail!" << endl;
				break;
			}
		}
		cout << "success 4" << endl;

		Sequence <int>* s;
		s = a.Copy();
		quckSorter<int> k{};
		k.Sort(*s);
		for (int x = 1; x < s->GetLength(); x++)
		{
			if (s->Get(x - 1) > s->Get(x))
			{
				cout << "Fail!" << endl;
				break;
			}
		}
		cout << "success 5" << endl;



		cout << "Test Passed successfully" << endl;
		break;

	}
	case 2:
	{
		ArraySequence <int> a;
		a.Append(4);
		a.Append(2);
		a.Append(1);
		a.Append(6);
		Sequence <int>* q;
		q = a.Copy();
		InsertSorter<int> b{};
		b.Sort(*q);
		cout << "\n";
		for (int x = 1; x < q->GetLength(); x++)
		{
			if (q->Get(x - 1) > q->Get(x))
			{
				cout << "Fail!" << endl;
				break;
			}
		}
		cout << "success 1" << endl;
		Sequence <int>* y;
		y = a.Copy();
		BubbleSorter<int> z{};
		z.Sort(*y);
		for (int x = 1; x < y->GetLength(); x++)
		{
			if (y->Get(x - 1) > y->Get(x))
			{
				cout << "Fail!" << endl;
				break;
			}
		}
		cout << "success 2" << endl;

		Sequence <int>* h;
		h = a.Copy();
		ShellSorter<int> u{};
		u.Sort(*h);
		for (int x = 1; x < h->GetLength(); x++)
		{
			if (h->Get(x - 1) > h->Get(x))
			{
				cout << "Fail!" << endl;
				break;
			}
		}
		cout << "success 3" << endl;

		Sequence <int>* j;
		j = a.Copy();
		PyramidSorter<int> l{};
		l.Sort(*j);
		for (int x = 1; x < j->GetLength(); x++)
		{
			if (j->Get(x - 1) > j->Get(x))
			{
				cout << "Fail!" << endl;
				break;
			}
		}
		cout << "success 4" << endl;

		Sequence <int>* s;
		s = a.Copy();
		quckSorter<int> k{};
		k.Sort(*s);
		for (int x = 1; x < s->GetLength(); x++)
		{
			if (s->Get(x - 1) > s->Get(x))
			{
				cout << "Fail!" << endl;
				break;
			}
		}
		cout << "success 5" << endl;



		cout << "Test Passed successfully" << endl;
		break;
	}
	}


}
