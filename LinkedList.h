#include <iostream>
#include <exception>
#include <stdio.h>
using namespace std;


template<typename T>
class LinkedList
{
private:


	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
		void setValue(T data) {
			this->data = data;
		}

	};
	int Size;
	Node<T>* head;



public:
	LinkedList()
	{
		Size = 0;
		head = nullptr;
	}
	LinkedList(T* items, int count)
	{
		if (count < 0)
			throw std::exception("Size < 0");
		this->Size = count;
		this->head = nullptr;
		T temp1;
		for (size_t i = 0; i < count; i++)
		{
			temp1 = items[i];
			if (head == nullptr)
			{
				head = new Node<T>(temp1);
			}
			else
			{
				Node<T>* temp2 = head;
				while (temp2->pNext != nullptr)
				{
					temp2 = temp2->pNext;
				}
				temp2->pNext = new Node<T>(temp1);
			}
		}
	}
	LinkedList(LinkedList<T>& other)
	{
		this->head = nullptr;
		for (size_t i = 0; i < other.Getlength(); i++)
		{
			this->prepend(other.Get(i));
		}
	}
	~LinkedList()
	{
		while (this->Size)
		{
			Remove(0);
		}
	}
	void setElem(int index, T value) {
		if (index < 0 || index >= this->Size)
			throw - 1;
		else {
			if (index == 0)
				this->head->setValue(value);
			else {
				Node<T>* el = this->head;
				el = el->pNext;
				for (int i = 1; i < index; i++)
					el = el->pNext;
				el->setValue(value);
			}
		}
	}
	void Remove(const int index)
	{
		if (index < 0 || index >= this->Size)
			throw std::exception("Index out of range ");
		if (index == 0)
		{
			Node<T>* temp = this->head;
			this->head = this->head->pNext;

			delete temp;

			this->Size--;
		}
		else
		{
			Node<T>* previous = this->head;

			for (int i = 0; i < index - 1; i++)
			{
				previous = previous->pNext;
			}
			Node<T>* ToDelete = previous->pNext;
			previous->pNext = ToDelete->pNext;

			delete ToDelete;
			this->Size--;
		}
	}
	void prepend(T data)
	{
		if (head == nullptr)
		{
			head = new Node<T>(data);
		}
		else
		{
			Node<T>* current = head;
			while (current->pNext != nullptr)
			{
				current = current->pNext;
			}
			current->pNext = new Node<T>(data);

		}

		Size++;
	}


	int Getlength()
	{
		return Size;
	}

	T GetFirst()
	{
		return Get(0);
	}

	T GetLast()
	{
		return Get(this->Size - 1);

	}

	// перегруженный оператор [] 
	T& operator[](const int index)
	{
		int counter = 0;

		Node<T>* current = this->head;

		while (current != nullptr)
		{
			if (counter == index)
			{
				return current->data;
			}
			current = current->pNext;
			counter++;
		}
	}
	T Get(const int index)
	{
		if (index < 0 || index >= this->Size)
			throw std::exception("index out of range ");
		int count = 0;
		Node<T>* current = this->head;
		while (current != nullptr)
		{
			if (count == index)
			{
				return current->data;
			}
			current = current->pNext;
			count++;
		}

	}

	LinkedList<T>* GetSubList(int startIndex, int endIndex)
	{
		if (startIndex > Size || endIndex > Size || startIndex < 0 || endIndex < 0)
		{
			throw std::exception("Index out of range");
		}
		else
		{
			Node<T>* current = this->head;
			LinkedList<T>* result = new LinkedList();
			int g = 0;
			while (g != startIndex)
			{
				current = current->pNext;
				g++;
			}
			int m = g - 1;
			while (m != endIndex)
			{
				result->prepend(current->data);
				current = current->pNext;
				m++;
			}
			return result;
		}
	}



	void append(T data)
	{
		head = new Node<T>(data, head);
		Size++;
	}

	void insertAt(T data, int index)
	{
		if (index < 0 || index >= this->Size)
			throw std::exception("index out of range ");
		if (index == 0)
		{
			append(data);
		}
		else
		{
			Node<T>* previous = this->head;

			for (int i = 0; i < index - 1; i++)
			{
				previous = previous->pNext;
			}

			Node<T>* newNode = new Node<T>(data, previous->pNext);

			previous->pNext = newNode;

			Size++;
		}
	}

	LinkedList<T>* Concat(LinkedList<T>* list)
	{
		LinkedList<T>* result = new LinkedList();
		Node<T>* list1 = this->head;

		while (list1 != nullptr)
		{
			result->prepend(list1->data);
			list1 = list1->pNext;
		}
		Node<T>* list2 = list->head;
		while (list2 != nullptr)
		{
			result->prepend(list2->data);
			list2 = list2->pNext;
		}
		return result;
	}
	void listPrintf() const {
		Node <T>* a = this->head;
		while (a != nullptr) {
			cout << a->data << " ";
			a = a->pNext;
		}
		cout << endl;
	}

};
