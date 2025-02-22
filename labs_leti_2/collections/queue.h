#pragma once
#include <stdexcept>

using namespace std;
/// <summary>
/// ����� Stack ��������� ���� � �������������� �������� ������.
/// ���� �������� �� �������� "��������� ������ � ������ �����" (LIFO).
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
	/// �����������, ���������������� ������ �������.
	/// </summary>
	Queue() : top(nullptr), bottom(nullptr), counter(0) {}

	/// <summary>
	/// ����������, ������� ����������� ��� ���������� �������.
	/// </summary>
	~Queue()
	{
		clear();
	}

	/// <summary>
	/// ��������� ������� � �������.
	/// </summary>
	/// <param name="value">�������, ������� ����� �������� � �������.</param>
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
	/// ��������� ������� �� �������.
	/// </summary>
	/// <returns>���������� ����������� �������.</returns>
	/// <exception cref="std::runtime_error">�������������, ���� ������� �����.</exception>
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
	/// ���������� ���������� ��������� � �������.
	/// </summary>
	/// <returns>���������� ��������� � �������.</returns>
	int count() const 
	{
		return counter;
	}

	/// <summary>
	/// ������� ��� �������� �� �������.
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