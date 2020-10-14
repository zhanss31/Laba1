#pragma once
#include "ArraySequence.h"
#include "ListSequence.h"
using namespace std;
template <class T>
class ISorter
{
public:
	virtual void Sort(Sequence<T>& input) = 0;
};

template <class T>
class BubbleSorter: public ISorter<T>
{
public:
	void Sort(Sequence<T>& input)
	{
		if (input.GetLength() == 0)
			return;
		BubbleSort(input);
     }
private:
	void BubbleSort(Sequence<T>& input)
	{
		long i, j;
		T x;
		for (i = 0; i < input.GetLength(); i++) {
			for (j = input.GetLength() - 1; j > i; j--) {
				if (input.Get(j - 1) > input.Get(j)) {
					x = input.Get(j - 1);
					input.setElem(j - 1, input.Get(j));
					input.setElem(j, x);
				}
			}
		}
	}
};
template <class T>
class quckSorter : public ISorter<T>
{
public:
	void Sort(Sequence<T>& input) 
	{
		if (input.GetLength() == 0)
			return;
		long left = 0;
		long right = input.GetLength() - 1;
		qSort(input,left,right);
	}
private:
	void qSort(Sequence<T>& input, long left, long right)
	{
		long pivot; 
		long l_hold = left;
		long r_hold = right;
		pivot = input.Get(left);
		while (left < right) 
		{
			while ((input.Get(right) >= pivot) && (left < right))
				right--;
			if (left != right) 
			{
				input.setElem(left, input.Get(right)); 
				left++; 
			}
			while ((input.Get(left) <= pivot) && (left < right))
				left++; 
			if (left != right) 
			{
				input.setElem(right, input.Get(left)); 
				right--; 
			}
		}
		input.setElem(left, pivot);
		pivot = left;
		left = l_hold;
		right = r_hold;
		if (left < pivot) 
			qSort(input, left, pivot - 1);
		if (right > pivot)
			qSort(input, pivot + 1, right);
	}


};

template <class T>
class PyramidSorter : public ISorter<T>
{
public:
	void Sort(Sequence<T>& input)
	{
		if (input.GetLength() == 0)
			return;
		heapSort(input, input.GetLength());
	}

private:
	// Функция "просеивания" через кучу - формирование кучи
	void siftDown(Sequence<T>& input, long root, long bottom)
	{
		int maxChild; 
		int done = 0; 
		while ((root * 2 <= bottom) && (!done))
		{
			if (root * 2 == bottom)    
				maxChild = root * 2;   
			else if (input.Get(root * 2) > input.Get(root * 2 + 1))
				maxChild = root * 2;
			else
				maxChild = root * 2 + 1;
			if (input.Get(root) < input.Get(maxChild))
			{
				long temp = input.Get(root); 
				input.setElem(root,input.Get(maxChild));
				input.setElem(maxChild, temp);
				root = maxChild;
			}
			else 
				done = 1; 
		}
	}
	// Функция сортировки на куче
	void heapSort(Sequence<T>& input,long size)
	{
		for (long i = (size / 2) - 1; i >= 0; i--)
			siftDown(input, i, size - 1);
		for (long i = size - 1; i >= 1; i--)
		{
			T temp = input.Get(0);
			input.setElem(0,input.Get(i));
			input.setElem(i, temp);
			siftDown(input, 0, i - 1);
		}
	}
};

template <class T>
class ShellSorter : public ISorter<T>
{
public:
	void Sort(Sequence<T>& input)
	{
		if (input.GetLength() == 0)
			return;
		Shell(input, input.GetLength());
	}
private:
	void Shell(Sequence<T>& input, long n)
	{
		int i, j, d, count;
		d = n;
		d = d / 2;
		while (d > 0)
		{
			for (i = 0; i < n - d; i++)
			{
				j = i;
				while (j >= 0 && input.Get(j)> input.Get(j + d))
				{
					count = input.Get(j);
					input.setElem(j, input.Get(j + d));
					input.setElem(j+d, count);
					j--;
				}
			}
			d = d / 2;
		}
	}
};

template <class T>
class InsertSorter : public ISorter<T>
{
public:
	void Sort(Sequence<T>& input)
	{
		if (input.GetLength() == 0)
			return;
		ISort(input, input.GetLength());
	}
private:
	void ISort(Sequence<T>& input, long n)
	{
		T temp, item; 
		for (int counter = 1; counter < n; counter++)
		{
			temp = input.Get(counter); 
			item = counter - 1; 
			while (item >= 0 && input.Get(item) > temp) 
			{
				input.setElem(item + 1, input.Get(item)); 
				input.setElem(item ,temp);
				item--;
			}
		}
	}
};


