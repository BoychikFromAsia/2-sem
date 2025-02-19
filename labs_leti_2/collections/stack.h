#pragma once

#include <stdexcept>

using namespace std;
/// <summary>
/// Класс Stack реализует стек с использованием связного списка.
/// Стек работает по принципу "последний пришел — первый вышел" (LIFO).
/// </summary>
template <typename T>
class Stack
{
private:
    struct Container
    {
        T data;
        Container* next;
    };

    Container* top = nullptr;
    int counter = 0;

public:
    /// <summary>
    /// Освобождает память, занятую элементами стека.
    /// </summary>
    ~Stack()
    {
        clear();
    }
    /// <summary>
    /// Добавляет элемент в стек.
    /// </summary>
    /// <param name="value">Значение, которое нужно добавить в стек.</param>
    void push(T value)
    {
        Container* temp = new Container();
        temp->data = value;
        temp->next = top;
        top = temp;
        counter++;
    }

    /// <summary>
    /// Удаляет верхний элемент из стека и возвращает его значение.
    /// </summary>
    /// <returns>Значение верхнего элемента стека.</returns>
    /// <exception cref="std::runtime_error">Выбрасывается, если стек пуст.</exception>
    T pop()
    {
        if (top == nullptr)
        {
            throw ("Stack is empty!");
        }
        Container* temp = top->next;
        T value = top->data;
        delete top;
        top = temp;
        counter--;
        return value;
    }

    /// <summary>
    /// Возвращает значение верхнего элемента стека без его удаления.
    /// </summary>
    /// <returns>Значение верхнего элемента стека.</returns>
    /// <exception cref="std::runtime_error">Выбрасывается, если стек пуст.</exception>
    T peek()
    {
        if (top == nullptr)
        {
            throw ("Stack is empty!");
        }
        return top->data;
    }
    
    /// <summary>
    /// Возвращает текущее количество элементов в стеке.
    /// </summary>
    /// <returns>Количество элементов в стеке.</returns>
    int count() const
    {
        return counter;
    }

    /// <summary>
    /// Очищает стек, удаляя все элементы.
    /// </summary>
    void clear()
    {
        while (top != nullptr)
        {
            Container* temp = top->next;
            delete top;
            top = temp;
        }
        counter = 0;
    }
};