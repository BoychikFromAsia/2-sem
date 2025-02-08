#include <iostream>
#include <stack>
using namespace std;

int n = 1;

void Push(stack <int> T, int n) {
	while (n != 0) {
		cout << "Введите число последовательности: ";
		cin >> n;
		T.push(n);
	}
	cout << T.size() - 1 << endl;	 // Использовал size вместо count, посколько его не было в библиотеке.
	while (!T.empty()) {
		if (T.top() > 0)	// Использовал top вместо peak, посколько его не было в библиотеке.
		{
			cout << "Числа последовательности: " << T.top() << endl;
		}
		T.pop();
	}
}
void clear(stack <int> T, int n) {
	while (!T.empty()) {
		T.pop();
	}
}
int main() {
	setlocale(LC_ALL, "RU");
	stack <int> T;
	Push(T, n);
	clear(T, n);
	return 0;
}