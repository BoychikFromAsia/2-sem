#include <iostream>
#include <stack.h>
using namespace std;

int n = 1;

int main() {
	setlocale(LC_ALL, "RU");
	Stack<int> T;
	while (n != 0) {
		cout << "Введите число последовательности: ";
		cin >> n;
		T.push(n);
	}
	while (T.count()) {
		if (T.peek() > 0)
		{
			cout << "Числа последовательности: "
				<< T.peek() 
				<< endl;
		}
		T.pop();
	}
	return 0;
}
