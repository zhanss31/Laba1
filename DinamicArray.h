#pragma once
#include <iostream>
using namespace std;
template<class T>
class DynamicArray
{
private:
	int arraySize;
	T* items;

public:
	DynamicArray(T* items, int count)
	{
		this->arraySize = count;
		this->items = new T[count];

		for (int i = 0; i < count; i++)
		{
			setElem(i, items[i]);
		}
	}

	DynamicArray(const int size)
	{
		if (size < 0)
			throw "Fatal Error";
		this->items = new T[size];
		this->arraySize = size;
	}

	DynamicArray(const DynamicArray<T>& array)
	{
		this->arraySize = array.arraySize;
		this->items = new T[this->arraySize];
		for (int i = 0; i < this->arraySize; i++)
		{
			setElem(i, array.items[i]);
		}
	}

	~DynamicArray()
	{
		delete[] items;

	}

	T getElem(int index)
	{
		if (index < 0 || index >= this->arraySize)
			throw ("Division by zero!");
		else return this->items[index];
	}

	int getSize()
	{
		return arraySize;
	}


	void setElem(int index, T value)
	{
		if (index < 0 || index >= this->arraySize)
			throw ("Division by zero!");
		else
		{
			this->items[index] = value;
		}
	}

	void resize(int newSize)
	{
		if (newSize < 0)
		{
			throw ("Division by zero!");
		}
		T* newItems = new T[newSize];
		if (newSize > this->arraySize)
		{
			for (int i = 0; i < this->arraySize; i++)
			{
				newItems[i] = getElem(i);
			}
			for (int i = this->arraySize; i < newSize; i++)
			{
				newItems[i] = 0;
			}
			delete (this->items);
			this->items = newItems;
		}
		else
		{
			this->arraySize = newSize;
			for (int i = 0; i < newSize; i++)
			{
				newItems[i] = getElem(i);
			}
			delete (this->items);
			this->items = newItems;
		}

	}
	void arrayPrintf() {
		for (int i = 0; i < this->getSize(); i++) {
			cout << this->getElem(i) << " ";
		}
		cout << endl;
	}
	
};


