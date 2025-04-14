#pragma once
#include <stdexcept>
#include "container.h"

using namespace std;

template<typename T>
class CycleList
{
private:
	Container<T>* last;
	Container<T>* first;
	int counter;

public:
	/// <summary>
	/// Конструктор по умолчанию.
	/// </summary>
	CycleList() : first(nullptr), last(nullptr), counter(0) {}

	/// <summary>
	/// Деструктор. Очищает список при уничтожении объекта.
	/// </summary>
	~CycleList()
	{
		clear();
	}

	/// <summary>
	/// Добавляет элемент в конец списка.
	/// </summary>
	/// <param name="data">Данные для добавления.</param>
	void add(T data)
	{
		Container<T>* temp = new Container<T>;
		if (last != nullptr)
		{
			last->next = temp;
			last = temp;
		}
		else
		{
			last = first = temp;
		}
		last->next = first;
		counter++;
	}

	/// <summary>
	/// Вставляет элемент в указанную позицию.
	/// </summary>
	/// <param name="index">Позиция для вставки (индексация с 0).</param>
	/// <param name="data">Данные для вставки.</param>
	/// <exception cref="out_of_range">Если индекс выходит за пределы списка.</exception>
	void insert(int index, T data)
	{
		if (index < 0 || index > counter)
		{
			throw out_of_range("Index out of range");
		}
		if (index == counter)
		{
			add(data);
			return;
		}
		Container<T>* temp = new Container<T>(data);
		if (index == 0)
		{
			temp->next = first;
			first = temp;
			last->next = first;
		}
		else
		{
			Container<T>* current = first;
			for (int i = 0; i < index - 1; i++)
			{
				current = current->next;
			}
			temp->next = current->next;
			current->next = temp;
		}
		counter++;
	}

	/// <summary>
	/// Удаляет элемент из списка по указанному индексу.
	/// </summary>
	/// <param name="index">Позиция для удаления (индексация с 0).</param>
	/// <exception cref="out_of_range">Если индекс выходит за пределы списка.</exception>
	void removeAt(int index)
	{
		if (index < 0 || index > counter)
		{
			throw out_of_range("Index out of range");
		}
		Container<T>* toDelete;
		if (index == 0)
		{
			toDelete = first;
			first = first->next;
			last->next = first;
			if (counter == 1)
			{
				first = last = nullptr;
			}
		}
		else
		{
			Container<T>* current = first;
			for (int i = 0; i < index - 1; i++)
			{
				current = current->next;
			}
			toDelete = current->next;
			current->next = toDelete->next;
			if (index == counter - 1)
			{
				last = current;
			}
		}
		delete toDelete;
		counter--;
	}

	/// <summary>
	/// Возвращает ссылку на элемент по указанному индексу.
	/// </summary>
	/// <param name="index">Индекс элемента (индексация с 0).</param>
	/// <returns>Ссылка на данные элемента.</returns>
	/// <exception cref="out_of_range">Если индекс выходит за пределы списка.</exception>
	T& operator[](const int index)
	{
		if (index < 0 || index >= counter)
		{
			throw out_of_range("Index out of range");
		}
		Container<T>* current = first;
		for (int i = 0; i < index; i++)
		{
			current = current->next;
		}
		return current->data;
	}

	/// <summary>
	/// Возвращает количество элементов в списке.
	/// </summary>
	/// <returns>Количество элементов.</returns>
	int count() const
	{
		return counter;
	}

	/// <summary>
	/// Подсчитывает количество вхождений указанного значения в списке.
	/// </summary>
	/// <param name="data">Значение для подсчета.</param>
	/// <returns>Количество вхождений.</returns>
	int count(T data) const
	{
		int matter = 0;
		Container<T>* current = first;
		for (int i = 0; i < counter; i++)
		{
			if (current->data == data)
			{
				matter++;
			}
			current = current->next;
		}
		return matter;
	}

	/// <summary>
	/// Очищает список, удаляя все элементы.
	/// </summary>
	void clear()
	{
		while (counter > 0)
		{
			removeAt(0);
		}
	}
};