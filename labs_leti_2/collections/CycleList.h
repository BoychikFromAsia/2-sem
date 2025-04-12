#pragma once
#include <stdexcept>
#include <container.h>

using namespace std;

template<typename T>
class CycleList
{
private:
	Container<T>* first;
	Container<T>* last;
	int counter;

public:

	CycleList() : first(nullptr), last(nullptr), counter(0) {}

	~CycleList()
	{
		clear();
	}

	void add(T value)
	{
		Container<T> temp = new Container<T>;
		temp->data = value;
		temp->next = first;
	}

	void insert(int, T)
	{

	}

	void removeAt(int)
	{

	}

	T& operator[](const int index)
	{

	}

	int count() const
	{
		return counter;
	}

	int count(T)
	{

	}

	void clear()
	{
		
		counter = 0;
	}
};