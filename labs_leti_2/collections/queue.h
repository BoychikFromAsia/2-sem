#pragma once

//#include <stdexcept>

using namespace std;

template <typename T>
class Queue
{
private:

	struct Container
	{
		T data;
		Container* next;
		
	};

	Container* top = nullptr;
	Container* bottom = nullptr;
	int counter = 0;

public: 

	~Queue()
	{
		clear();
	}

	void queue(T value) // добавляет элемент в очередь
	{
		Container* temp = new Container();
		temp->data = value;
		
		if (bottom == nullptr)
		{
			temp->next = bottom;
			bottom = temp;
			top = temp;
		}
		else 
		{
			top->next = temp;
			top = temp;
		}
		counter++;
	}

	T unqueue() // извлекает элемент из очереди
	{
		if (top == nullptr)
		{
			throw "queue is empty";
		}
		if (bottom == nullptr)
		{
			throw "queue is empty";
		}
		Container* temp = bottom->next;
		T value = bottom->data;
		delete bottom;
		bottom = temp;
		counter--;
		return value;
	}

	int count() const // возвращает количество элементов коллекции
	{
		return counter;
	}

	void clear() //  удаляет все элементы коллекции
	{
		while (top != 0)
		{
			Container* temp = top->next;
			delete top;
			top = temp;
		}
		bottom = nullptr;
		top = nullptr;
		counter = 0;
	}
};