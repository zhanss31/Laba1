#include "ISorter.h"
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	long i;
	int b;

	cout << "Сравнение эффективности сортировок:" << endl;
	cout << "Выберети реализацию:ListSequence-1, ArraySequence -2" << endl;
	int g;
	cin >> g;
	cout << endl;
	switch (g)
	{
	case 1:
	{
		ListSequence<int> p;
		for (i = 0; i < 10000; i++)
		{
			b = rand() % 100;
			p.Prepend(b);
		}
		int r=0;
		do {
			cout << "Выберите сортировку: 0-bubble sort,  1-quick sort,   2-pyramid sort,  3 -shell sort, 4- insert sort , 5- выйти из программы" << endl;
			cin >> r;
			cout << endl;
			switch (r)
			{
			case 0:
			{
				cout << "Bubble Sort:";
				Sequence <int>* seq1;
				seq1 = p.Copy();
				BubbleSorter<int> bubble{};
				unsigned int start_time = clock();
				bubble.Sort(*seq1);
				unsigned int end_time = clock();
				cout << end_time - start_time << endl;
				break;
			}
			case 1:
			{
				cout << "quick Sort:";
				Sequence <int>* seq2;
				seq2 = p.Copy();
				quckSorter<int> quck{};
				unsigned int start_time1 = clock();
				quck.Sort(*seq2);
				unsigned int end_time1 = clock();
				cout << end_time1 - start_time1 << endl;
				break;
			}
			case 2:
			{
				cout << "Pyramid Sort:";
				Sequence <int>* seq2;
				seq2 = p.Copy();
				PyramidSorter<int> pyram{};
				unsigned int start_time1 = clock();
				pyram.Sort(*seq2);
				unsigned int end_time1 = clock();
				cout << end_time1 - start_time1 << endl;
				break;
			}
			case 3:
			{
				cout << "Shell Sort:";
				Sequence <int>* seq2;
				seq2 = p.Copy();
				ShellSorter<int> shell{};
				unsigned int start_time1 = clock();
				shell.Sort(*seq2);
				unsigned int end_time1 = clock();
				cout << end_time1 - start_time1 << endl;
				break;
			}
			case 4:
			{
				cout << "Insert Sort:";
				Sequence <int>* seq2;
				seq2 = p.Copy();
				InsertSorter<int> insert{};
				unsigned int start_time1 = clock();
				insert.Sort(*seq2);
				unsigned int end_time1 = clock();
				cout << end_time1 - start_time1 << endl;
				break;
			}
			}

		} while (r!=5);
		cout << endl;
		break;
	}
	case 2:
	{
		ArraySequence<int> p;
		for (i = 0; i < 10000; i++)
		{
			b = rand() % 100;
			p.Prepend(b);
		}
		int r = 0;
		do {
			cout << "Выберите сортировку: 0-bubble sort,  1-quick sort,   2-pyramid sort,  3 -shell sort, 4- insert sort , 5- выйти из программы" << endl;
			cin >> r;
			cout << endl;
			switch (r)
			{
			case 0:
			{
				cout << "Bubble Sort:";
				Sequence <int>* seq1;
				seq1 = p.Copy();
				BubbleSorter<int> bubble{};
				unsigned int start_time = clock();
				bubble.Sort(*seq1);
				unsigned int end_time = clock();
				cout << end_time - start_time << endl;
				break;
			}
			case 1:
			{
				cout << "quick Sort:";
				Sequence <int>* seq2;
				seq2 = p.Copy();
				quckSorter<int> quck{};
				unsigned int start_time1 = clock();
				quck.Sort(*seq2);
				unsigned int end_time1 = clock();
				cout << end_time1 - start_time1 << endl;
				break;
			}
			case 2:
			{
				cout << "Pyramid Sort:";
				Sequence <int>* seq2;
				seq2 = p.Copy();
				PyramidSorter<int> pyram{};
				unsigned int start_time1 = clock();
				pyram.Sort(*seq2);
				unsigned int end_time1 = clock();
				cout << end_time1 - start_time1 << endl;
				break;
			}
			case 3:
			{
				cout << "Shell Sort:";
				Sequence <int>* seq2;
				seq2 = p.Copy();
				ShellSorter<int> shell{};
				unsigned int start_time1 = clock();
				shell.Sort(*seq2);
				unsigned int end_time1 = clock();
				cout << end_time1 - start_time1 << endl;
				break;
			}
			case 4:
			{
				cout << "Insert Sort:";
				Sequence <int>* seq2;
				seq2 = p.Copy();
				InsertSorter<int> insert{};
				unsigned int start_time1 = clock();
				insert.Sort(*seq2);
				unsigned int end_time1 = clock();
				cout << end_time1 - start_time1 << endl;
				break;
			}
			}

		} while (r != 5);
		cout << endl;
		break;
	}
	}
	
}
