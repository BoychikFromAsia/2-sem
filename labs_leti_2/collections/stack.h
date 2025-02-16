#pragma once

template <typename T>
struct Stack
{
	struct Container {
		T data;
		Container* next;
	};

	Container* top = nullptr;
	int counter = 0;

	void push(T value) {
		Container* temp = new Container();
		temp->data = value;
		temp->next = top;
		top = temp;
		counter++;
	}

	T pop() {
		if (top == nullptr) {
			throw "Stack is empty!";
		}
		Container* temp = top->next;
		T value = top->data;
		delete top;
		top = temp;
		counter--;
		return value;
	}

	T peek()
	{
		if (top == nullptr) {
			throw "Stack is empty!";
		}
		Container* temp = top->next;
		T value = top->data;
		return value;
	}

	int count()
	{
		return counter;
	}

	void clear()
	{
		while (top != nullptr) {
			Container* temp = top->next;
			delete top;
			top = temp;
		}
		counter = 0;
	}
};