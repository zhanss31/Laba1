#include "DinamicArray.h"
int main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите размер массива";
	std::cin >> n;
	cout << "Введите с каким типом данных вы хотите работать:int-1 double-2" << endl;;
	int g;
	std::cin >> g;
	switch (g)
	{
	case 1:
	{
		DynamicArray <int> a(n);
		cout << "Введите элементы массива" << endl;
		for (int i = 0; i < a.getSize(); i++)
		{
			int b;
			cout << "a[" << i << "]=";
			std::cin >> b;
			a.setElem(i, b);
		}

		cout << "Вывод  элементов массива" << endl;
		for (int i = 0; i < a.getSize(); i++)
		{
			cout << "a[" << i << "]=" << a.getElem(i) << endl;
		}

		cout << "Введите новый размер массива " << endl;
		std::cin >> n;
		a.resize(n);

		cout << "Вывод нового массива" << endl;
		for (int i = 0; i < a.getSize(); i++)
		{
			cout << "a[" << i << "]=" << a.getElem(i) << endl;
		}

		break;
	}
	case 2:
	{
		DynamicArray <double> a(n);
		cout << "Введите элементы массива" << endl;
		for (int i = 0; i < a.getSize(); i++)
		{
			int b;
			cout << "a[" << i << "]=";
			std::cin >> b;
			a.setElem(i, b);
		}

		cout << "Вывод  элементов массива" << endl;
		for (int i = 0; i < a.getSize(); i++)
		{
			cout << "a[" << i << "]=" << a.getElem(i) << endl;
		}

		cout << "Введите новый размер массива " << endl;
		std::cin >> n;
		a.resize(n);

		cout << "Вывод нового массива" << endl;
		for (int i = 0; i < a.getSize(); i++)
		{
			cout << "a[" << i << "]=" << a.getElem(i) << endl;
		}

		break;
	}
	}

	return 0;
};
