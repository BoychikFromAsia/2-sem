#include <iostream>
#include <queue.h>

using namespace std;

void insertBeforeNegatives(Queue<int>& queue)
{
	for (int i = 0; i < queue.count(); i++)
	{
		int tempNum = queue.unqueue();
		if (tempNum < 0)
		{
			queue.queue(1);
			i++;
		}
		queue.queue(tempNum);
	}
}

void removeNegatives(Queue<int>& queue)
{
	for (int i = 0; i < queue.count(); i++)
	{
		int tempNum = queue.unqueue();
		if (tempNum >= 0)
		{
			queue.queue(tempNum);
		}
		else
		{
			i--;
		}
	}
}

int countOccurrences(Queue<int>& queue, int checkNum)
{
	int counter = 0;
	for (int i = 0; i < queue.count(); i++)
	{
		int tempNum = queue.unqueue();
		queue.queue(tempNum);
		if (tempNum == checkNum)
		{
			counter++;
		}
	}
	return counter;
}

void displayOccurrences(int checkNum, int counter)
{
	if (counter != 0)
	{
		cout << "Число "
			<< checkNum
			<< " встречается "
			<< counter
			<< " раз/раза."
			<< endl;
	}
	else
	{
		cout << "Данное число не встречается в очереди."
			<< endl;
	}
}

void displayMenu()
{
	cout << "Выберите операцию: \n"
		<< "1 - Добавление одного элемента \n"
		<< "2 - Извлечение одного элемента \n"
		<< "3 - Возвращение количества элементов коллекции \n"
		<< "4 - Удаление всех элементов коллекции \n"
		<< "5 - Вставка перед отрицательным числом элемент со значением 1 \n"
		<< "6 - Удаление всех отрицательных элементов коллекции \n"
		<< "7 - Подсчет колиества вхождения в очередь значения \n"
		<< "8 - Закрыть меню \n";
}

int main()
{
	setlocale(LC_ALL, "RU");
	Queue<int> queue;
	while (true)
	{
		int choice;
		displayMenu();
		cin >> choice;
		switch (choice)
		{
			case 1: 
				int input;
				cout << "Введите элемент для добавление в очередь: ";
				cin >> input;
				queue.queue(input);
				break;

			case 2: 
				cout << "Из очереди было извлечено значение: "
					<< queue.unqueue()
					<< endl;
				break;

			case 3: 
				cout << queue.count()
					<< endl;
				break;

			case 4: 
				queue.clear();
				break;

			case 5: 
				insertBeforeNegatives(queue);
				break;

			case 6: 
				removeNegatives(queue);
				break;

			case 7:
			{
				int checkNum;
				cout << "Введите число для проверки: ";
				cin >> checkNum;
				int counter = countOccurrences(queue, checkNum);
				displayOccurrences(checkNum, counter);
			}
			break;

			case 8: 
				return 0;

			default:
				cout << "Нет такой операции \n";
				break;
		}
	}
	return 0;
}