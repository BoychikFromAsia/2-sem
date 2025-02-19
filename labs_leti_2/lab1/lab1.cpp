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
		int num = stack.pop();
		if (num > 0) 
		{
			cout << "Числа последовательности: " 
				<< num << endl;
		}
	}
	return 0;
}