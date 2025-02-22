#pragma once
#include <stdexcept>

using namespace std;
/// <summary>
/// Класс Stack реализует стек с использованием связного списка.
/// Стек работает по принципу "последний пришел — первый вышел" (LIFO).
/// </summary>
template <typename T>
class Queue
{
private:

	struct Container
	{
		T data;
		Container* next;
		
	};

	Container* top;
	Container* bottom;
	int counter;

public: 
	/// <summary>
	/// Конструктор, инициализирующий пустую очередь.
	/// </summary>
	Queue() : top(nullptr), bottom(nullptr), counter(0) {}

	/// <summary>
	/// Деструктор, который освобождает все выделенные ресурсы.
	/// </summary>
	~Queue()
	{
		clear();
	}

	/// <summary>
	/// Добавляет элемент в очередь.
	/// </summary>
	/// <param name="value">Элемент, который будет добавлен в очередь.</param>
	void queue(T value) 
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

	/// <summary>
	/// Извлекает элемент из очереди.
	/// </summary>
	/// <returns>Возвращает извлеченный элемент.</returns>
	/// <exception cref="std::runtime_error">Выбрасывается, если очередь пуста.</exception>
	T unqueue() 
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

	/// <summary>
	/// Возвращает количество элементов в очереди.
	/// </summary>
	/// <returns>Количество элементов в очереди.</returns>
	int count() const 
	{
		return counter;
	}

	/// <summary>
	/// Удаляет все элементы из очереди.
	/// </summary>
	void clear() 
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