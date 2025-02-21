#include <iostream>
#include <queue.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	Queue <int> queue;
	int input = 1;
	int choice;
	int menu = 1;
	while (menu != 0)
	{
		cout << "Выберите операцию: \n"
			<< "1 - Ввод чисел \n"
			<< "2 - Вывод чисел \n"
			<< "3 - Вставка единицы перед отрицательным числом \n"
			<< "4 - Удаление элементов с отрицательное информационной частью \n"
			<< "5 - Количество вхождений в очередь \n"
			<< "6 - Удаление всех элементов \n"
			<< "7 - Закрыть меню \n";
		cin >> choice;;
	
		switch (choice)
		{
			
		case 1: // ввод последовательности
			while (input != 0)
			{
				cout << "Введите числа последовательности: ";
				cin >> input;
				if (input != 0)
				{
					queue.queue(input);
				}
			}
			break;


		case 2: // вывод последовательности
			while (queue.count() > 0)
			{
				cout << "Числа последовательности: "
					<< queue.unqueue()
					<< endl;
			}
			break;
			

		case 3: //вставка перед каждым отрицательным числом очереди элемента со значением 1
			while (queue.count())
			{
				if (queue.unqueue() < 0)
				{
					cout << "1 "
						<< queue.unqueue()
						<< endl;
				}
				else if (queue.unqueue() > 0)
				{
					cout << queue.unqueue()
						<< endl;
				}
			}
			break;

		case 4: //удаление из очереди всех элементов с отрицательной информационной частью
			while (queue.count())
			{
				if (queue.unqueue() < 0)
				{
					queue.unqueue();
				}
				else
				{
					continue;
				}
			}
			break;

		case 5: // подсчет количества вхождений в очередь значения введенного пользователем
			cout << queue.count()
				<<endl;
			break;

		case 6: // удаление всех элементов 
			queue.clear();
			break;

		case 7: //закрыть меню
			menu = 0;
			break;
		default:
			cout << "error \n";
			break;
		}
	}
	return 0;
}
	
