#include "LinkedList.h"
#include "Sequence.h"
template <class T >
class ListSequence : public Sequence<T>
{
private:
	LinkedList<T>* items;
	int count;
public:

	ListSequence(LinkedList<T>* items, int count)
	{
		this->items = new LinkedList<T>(items, count);
	}
	ListSequence()
	{
		this->items = new LinkedList<T>();
	}
	ListSequence(const ListSequence<T>& other)
	{
		this->items = new LinkedList<T>(*other.items);
		this->count = other.count;
	}
	~ListSequence()
	{
		delete items;
	}
public:
	void setElem(int index, T value) {
		if (index < 0 || index >= this->items->Getlength())
			throw - 1;
		else {
			this->items->setElem(index, value);
		}
	}
	int GetLength() const
	{
		return this->items->Getlength();
	}
	T GetFirst() const
	{
		return this->items->GetFirst();
	}
	T GetLast() const
	{
		return this->items->GetLast();
	}
	T Get(const int index) const
	{
		if (index < 0 || index >= this->count)
			throw std::exception("Index out of range ");
		return this->items->Get(index);
	}
public:
	void Append(T const value)
	{
		this->items->append(value);
		this->count++;
	}
	void Prepend(T const value)
	{
		this->items->prepend(value);
		this->count++;
	}
	void InsertAt(const int index, T const value)
	{
		this->items->insertAt(value, index);
		this->count++;
	}

	void Remove(T value)
	{
		int size = this->GetLength();
		for (size_t i = 0; i < size; i++)
		{
			if (this->items->Get(i) == value)
			{
				this->items->Remove(i);
				this->count--;
				break;
			}
		}
	}
	void RemoveAt(const int index)
	{
		if (index < 0 || index >= this->count)
			throw std::exception("Index out of range ");
		Remove(this->Get(index));
	}
	void RemoveAll(T value)
	{
		int size = this->GetLength();
		size_t j = 0;
		while (j < this->count)
		{
			if (this->items->Get(j) == value)
			{
				RemoveAt(j);
				j--;
			}
			j++;
		}
	}

	Sequence<T>* GetSubsequence(const int start, const int end) const
	{
		if (start < 0 || start >= this->count || end < 0 || end >= this->count)
			throw std::exception("Index out of range ");
		ListSequence<T>* getItemsSub = new ListSequence();
		getItemsSub->items = this->items->GetSubList(start, end);
		getItemsSub->count = getItemsSub->GetLength();

		return  getItemsSub;
	}
	Sequence<T>* Concat(Sequence<T>* other)
	{
		int size1 = this->GetLength();
		int size2 = other->GetLength();
		Sequence<T>* result = new ListSequence();
		for (size_t i = 0; i < size1; i++)
		{
			result->Prepend(this->Get(i));
		}
		for (size_t i = 0; i < size2; i++)
		{
			result->Prepend(other->Get(i));
		}
		return result;
	}
	ListSequence<T>* Copy()
	{
		ListSequence<T>* result = new ListSequence();
		for (size_t i = 0; i < this->items->Getlength(); i++)
			result->Prepend(this->Get(i));
		return result;
	}
	ListSequence<T>* CopyTo(Sequence<T>* purpose, int startIndex)
	{
		if (startIndex < 0 || startIndex > this->count)
			throw std::exception("Index out of range ");
		ListSequence<T>* result = new ListSequence();
		for (size_t i = 0; i < startIndex; i++)
			result->Prepend(purpose->Get(i));
		for (size_t i = 0; i < this->GetLength(); i++)
			result->Prepend(this->Get(i));
		return result;
	}
	void Printf() const {
		this->items->listPrintf();
	}
};
