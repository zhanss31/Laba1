#pragma once
#include "Sequence.h"
#include "DinamicArray.h"
using namespace std;
template <class T>
class ArraySequence : public Sequence<T>
{
private:
	DynamicArray<T>* items;
	int count;
public:
	ArraySequence(T* items, int count)
	{
		this->items = new DynamicArray<T>(items, count);
	}

	ArraySequence(int count)
	{
		this->items = new DynamicArray<T>(count);
	}

	ArraySequence()
	{
		this->items = new DynamicArray<T>(0);
	}

	ArraySequence(const DynamicArray<T>& array) {
		this->items = new DynamicArray<T>(*array.items);
		this->count = array.count;
	}
	~ArraySequence()
	{
		delete items;
	}
public:
	void setElem(int index, T value) {
		if (index < 0 || index >= this->items->getSize())
			throw - 1;
		else {
			this->items->setElem(index, value);
		}
	}
	int GetLength() const
	{
		return this->items->getSize();
	}
	T GetFirst() const
	{
		return this->items->getElem(0);
	}
	T GetLast() const
	{
		return this->items->getElem(this->items->getSize() - 1);
	}
	T Get(const int index) const
	{
		if (index < 0 || index >= this->count)
			throw ("Index out of range ");
		return this->items->getElem(index);
	}

	Sequence<T>* GetSubsequence(const int start, const int end) const
	{
		if (start < 0 || start >= this->count || end < 0 || end >= this->count)
			throw ("Index out of range");
		Sequence<T>* result = new ArraySequence();
		size_t j = 0;
		for (size_t i = start; i <= end; i++)
		{
			result->Prepend(this->Get(i));
		}
		return result;
	}
public:
	void Append(T value)
	{
		this->count++;
		DynamicArray<T>* addItems;
		addItems = new DynamicArray<T>(this->count);
		addItems->setElem(0, value);
		for (size_t i = 1; i < this->count; i++)
		{
			addItems->setElem(i, this->items->getElem(i - 1));
		}
		delete this->items;
		this->items = addItems;
	}
	void Prepend(T value)
	{
		this->count++;
		DynamicArray<T>* addItems;
		addItems = new DynamicArray<T>(this->count);
		for (size_t i = 0; i < this->count - 1; i++)
		{
			addItems->setElem(i, this->items->getElem(i));
		}
		addItems->setElem(this->count - 1, value);
		delete this->items;
		this->items = addItems;
	}
	void InsertAt(const int index, T value) 
	{
		if (index < 0 || index > this->count)
			throw ("Index out of range ");
		if (index == 0)
		{
			Append(value);
		}
		if (index == this->count)
		{
			Prepend(value);
		}
		if (index != 0 || index != this->count - 1)
		{
			this->count++;
			DynamicArray<T>* addItems;
			addItems = new DynamicArray<T>(this->count);
			for (size_t i = 0; i < index; i++)
			{
				addItems->setElem(i, this->items->getElem(i));
			}
			addItems->setElem(index, value);
			for (size_t i = index; i < this->count - 1; i++)
			{
				addItems->setElem(i + 1, this->items->getElem(i));
			}
			delete items;
			this->items = addItems;
		}
	}

	void RemoveAt(int index)
	{
		if (index < 0 || index >= this->count)
			throw ("Index out of range ");
		this->count--;
		DynamicArray<T>* removeItems;
		removeItems = new DynamicArray<T>(this->count);
		for (size_t i = 0; i < index; i++)
		{
			removeItems->setElem(i, this->items->getElem(i));
		}
		for (size_t i = index; i < count; i++)
		{
			removeItems->setElem(i, this->items->getElem(i + 1));
		}
		delete items;
		this->items = removeItems;
	}
	void Remove(T value)
	{
		int index;
		for (int i = 0; i < this->count; i++)
		{
			if (this->items->getElem(i) == value)
			{
				index = i;
				break;
			}
		}
		RemoveAt(index);
	}
	void RemoveAll(T value)
	{
		int size = this->count;
		size_t j = 0;
		while (j < this->count)
		{
			if (this->items->getElem(j) == value)
			{
				RemoveAt(j);
				j--;
			}
			j++;
		}
	}


	Sequence<T>* Concat(Sequence<T>* other)
	{
		Sequence<T>* concatItem = new ArraySequence();
		for (size_t i = 0; i < this->count; i++)
		{
			concatItem->Prepend(this->Get(i));
		}
		for (size_t i = 0; i < other->GetLength(); i++)
		{
			concatItem->Prepend(other->Get(i));
		}
		return concatItem;
	}
	Sequence<T>* Copy()
	{
		Sequence<T>* copyItems;
		copyItems = new ArraySequence();
		for (size_t i = 0; i < this->count; i++)
		{
			copyItems->Prepend(this->Get(i));
		}
		return copyItems;
	}
	Sequence<T>* CopyTo(Sequence<T>* target, int startIndex)
	{
		if (startIndex < 0 || startIndex > this->count)
			throw ("Index out of range ");
		Sequence<T>* copyItems = new ArraySequence();
		for (size_t i = 0; i < startIndex; i++)
			copyItems->Prepend(target->Get(i));

		for (size_t i = 0; i < this->GetLength(); i++)
			copyItems->Prepend(this->Get(i));
		return copyItems;
	}
	void Printf() const {
		this->items->arrayPrintf();
	}
};
