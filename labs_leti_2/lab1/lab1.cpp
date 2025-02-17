#include <iostream>
#include <stack.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	Stack<int> stack;
	int input = 1;
	while (input != 0) 
	{
		cout << "Введите число последовательности: ";
		cin >> input;
		if (input != 0) 
		{
			stack.push(input);
		}
	}
	while (stack.count()) 
	{
		if (stack.peek() > 0) 
		{
			cout << "Числа последовательности: "
				<< stack.pop()
				<< endl;
		}
		else 
		{
			stack.pop();
		}
	}
	return 0;
}
