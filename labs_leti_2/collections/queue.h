#pragma once
#include <stdexcept>
#include <container.h>

using namespace std;

/// <summary>
/// Класс Queue реализует очередь с использованием связного списка.
/// Очередь работает по принципу "первый пришел — первый вышел" (FIFO).
/// </summary>
template <typename T>
class Queue
{
private:
	Container<T>* top;
	Container<T>* bottom;
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
		Container<T>* temp = new Container<T>;
		temp->data = value;
		temp->next = nullptr;

		if (bottom == nullptr)
		{
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
		if (bottom == nullptr)
		{
			throw "queue is empty";
		}
		Container<T>* temp = bottom->next;
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
		while (top != nullptr)
		{
			Container<T>* temp = top->next;
			delete top;
			top = temp;
		}
		bottom = nullptr;
		top = nullptr;
		counter = 0;
	}
};