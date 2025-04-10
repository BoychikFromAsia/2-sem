#pragma once
#include <stdexcept>
#include <container.h>

using namespace std;

template<typename T>
class CycleList
{
private:
	Container<T>* top;
	Container<T>* bottom;
	int counter;

public:
};