#include <iostream>
#include <queue.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	Queue <int> queue;
	int choice;
	int menu = 1;
	int counter = 0;
	while (menu != 0)
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
		cin >> choice;
		switch (choice)
		{
		case 1: 
			int input;
			cout << "Введите элемент для добавление в очередь: "
				<< endl;
			cin >> input;
			queue.queue(input);
			break;

		case 2: 
			cout << "Вы извлекаете один элемент из очереди: "
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
			int temp_num;
			for (int i=0;i < queue.count();i++)
			{
				temp_num = queue.unqueue();
				if (temp_num < 0)
				{
					queue.queue(1);
					i++;
				}
				queue.queue(temp_num);
			}
			break;

		case 6: 
			for (int i = 0; i < queue.count();i++)
			{
				int temp_num = queue.unqueue();
				if (temp_num >= 0)
				{
					queue.queue(temp_num);
				}
				else 
				{
					i--;
				}
			}
			break;

		case 7: 
			int check_num;
			cout << "Введите число для проверки: ";
			cin >> check_num;
			for (int i = 0; i < queue.count();i++)
			{
				int temp_num = queue.unqueue();
				queue.queue(temp_num);
				if (temp_num == check_num)
				{
					counter++;
				}
			}
			if (counter != 0)
			{
				cout << "Число "
					<< check_num
					<< " встречается "
					<< counter
					<< " раз/раза."
					<< endl;
			}
			else
			{
				cout << "Данное число не встречается в очереди."
					<<endl;
			}
			break;

		case 8: 
			menu = 0;
			break;

		default:
			cout << "Нет такой операции \n";
			break;
		}
	}
	return 0;
}