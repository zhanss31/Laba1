#include "ISorter.h"
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	int choice=0;
	long size_array;
	int typeseq;
	ISorter<int>* sorts[5];
	std::string sortNames[5];

	sortNames[0] = "Bubble sort";
	sortNames[1] = "Insert sort";
	sortNames[2] = "Quick sort";
	sortNames[3] = "Heap sort";
	sortNames[4] = "Shell sort";

	BubbleSorter<int> bs{};
	InsertSorter<int> ins{};
	quckSorter<int> qs{};
	PyramidSorter<int> hs{};
	ShellSorter<int> shs{};
	sorts[0] = &bs;
	sorts[1] = &ins;
	sorts[2] = &qs;
	sorts[3] = &hs;
	sorts[4] = &shs;

	cout << "Сравнение эффективности сортировок:" << endl;
	cout << "Введите количество элементов рандомного массива"<<endl;
	cin >> size_array;
	while (choice != 6)
	{
		int*Array = new int[size_array];
		for (int i = 0; i < size_array; i++) {
			Array[i] = rand()%100;
		}
		for (int i = 0; i < size_array; i++) {
			cout<<Array[i]<<" ";
		}
		cout << endl;
		cout << "Выберети реализацию:" << endl;
		cout << "ListSequence-1"<<endl;
		cout << "ArraySequence-2" << endl;
		cin >> typeseq;
		Sequence <int>* seq;
	
		if (typeseq == 1)
		{
			seq = new ArraySequence<int>(Array, size_array);
		}
		if (typeseq== 2)
		{
			seq = new ListSequence<int>(Array, size_array);
		}
		cout << "Выберите сортировку:" << endl;
		cout << "Bubble Sort-1" << endl;
		cout << "Insert Sort-2" << endl;
		cout << "quick Sort-3" << endl;
		cout << "Pyramid Sort-4" << endl;
		cout << "Shell Sort-5 " << endl;
		cout << "end- 6" << endl;
		cin >> choice;
		if (choice == 6)
			break;
		unsigned int start_time = clock();
		sorts[choice - 1]->Sort(*seq);
		unsigned int end_time = clock();
		cout<<sortNames[choice-1]<<": "<< end_time - start_time << endl;
		

	}
}
