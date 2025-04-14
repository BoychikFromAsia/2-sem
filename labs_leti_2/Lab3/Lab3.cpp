#include <iostream>
#include "CycleList.h"

using namespace std;

/// <summary>
/// Вставляет 1 перед каждым отрицательным элементом списка.
/// </summary>
/// <param name="list">Список, в который производится вставка.</param>
void insertBeforeNegatives(CycleList<int>& list)
{
    int count = list.count();
    for (int i = 0; i < count; i++)
    {
        if (list[i] < 0)
        {
            list.insert(i, 1);
            i++;
            count++;
        }
    }
}
/// <summary>
/// Удаляет все отрицательные элементы из списка.
/// </summary>
/// <param name="list">Список, из которого производится удаление.</param>
void removeNegatives(CycleList<int>& list)
{
    int i = 0;
    while (i < list.count())
    {
        if (list[i] < 0)
        {
            list.removeAt(i);
        }
        else
        {
            i++;
        }
    }
}
/// <summary>
/// Выводит содержимое списка на экран.
/// </summary>
/// <param name="list">Список для вывода.</param>
void printList(CycleList<int>& list)
{
    for (int i = 0; i < list.count(); i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}

void displayMenu()
{
    cout << "1. Добавить элемент" << endl;
    cout << "2. Вставить элемент" << endl;
    cout << "3. Удалить элемент по индексу" << endl;
    cout << "4. Получить элемент по индексу" << endl;
    cout << "5. Посчитать количество элементов" << endl;
    cout << "6. Посчитать количество вхождений значения" << endl;
    cout << "7. Очистить список" << endl;
    cout << "8. Вставить 1 перед каждым отрицательным элементом" << endl;
    cout << "9. Удалить все отрицательные элементы" << endl;
    cout << "10. Вывести список" << endl;
    cout << "0. Выйти" << endl;
    cout << "Выберите опцию: ";
}

int cases(int choice, CycleList<int> list)
{
    switch (choice)
    {
    case 1:
    {
        int value; 
        cout << "Введите значение: ";
        cin >> value;
        list.add(value);
        break;
    }
    case 2:
    {
        int index, value;
        cout << "Введите индекс и значение: ";
        cin >> index >> value;
        list.insert(index, value);
        break;
    }
    case 3:
    {
        int index; 
        cout << "Введите индекс: ";
        cin >> index;
        list.removeAt(index);
        break;
    }
    case 4:
    {
        int index; 
        cout << "Введите индекс: ";
        cin >> index;
        try
        {
            cout << "Элемент с индексом " << index << ": " << list[index] << endl;
        }
        catch (out_of_range& e)
        {
            cout << e.what() << endl;
        }
        break;
    }
    case 5:
        cout << "Количество элементов: " << list.count() << endl;
        break;
    case 6:
    {
        int value; 
        cout << "Введите значение: ";
        cin >> value;
        cout << "Количество вхождений " << value << ": " << list.count(value) << endl;
        break;
    }
    case 7:
        list.clear();
        cout << "Список очищен." << endl;
        break;
    case 8:
        if (list.count() == 0)
            cout << "Список пуст" << endl;
        else
        {
            insertBeforeNegatives(list);
            cout << "Вставлены 1 перед отрицательными элементами." << endl;
            break; 
        }
    case 9:
        if (list.count() == 0)
            cout << "Список пуст" << endl;
        else
        {
            removeNegatives(list);
            cout << "Отрицательные элементы удалены." << endl;
            break; 
        }
    case 10:
        printList(list);
        break;
    case 0:
        return 0; 
    default:
        cout << "Неверная опция." << endl;
        break; 
    }
}

int main()
{
    setlocale(LC_ALL, "RU");
    CycleList<int> list;
    int choice, value, index;
    while (true)
    {
        displayMenu();
        while (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ошибка: введите число от 0 до 10." << endl;
            displayMenu();
        }
        cases(choice, list);
    }
    return 0;
}  