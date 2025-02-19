#pragma once

#include <stdexcept>

using namespace std;
/// <summary>
/// ����� Stack ��������� ���� � �������������� �������� ������.
/// ���� �������� �� �������� "��������� ������ � ������ �����" (LIFO).
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
    /// ����������� ������, ������� ���������� �����.
    /// </summary>
    ~Stack()
    {
        clear();
    }
    /// <summary>
    /// ��������� ������� � ����.
    /// </summary>
    /// <param name="value">��������, ������� ����� �������� � ����.</param>
    void push(T value)
    {
        Container* temp = new Container();
        temp->data = value;
        temp->next = top;
        top = temp;
        counter++;
    }

    /// <summary>
    /// ������� ������� ������� �� ����� � ���������� ��� ��������.
    /// </summary>
    /// <returns>�������� �������� �������� �����.</returns>
    /// <exception cref="std::runtime_error">�������������, ���� ���� ����.</exception>
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
    /// ���������� �������� �������� �������� ����� ��� ��� ��������.
    /// </summary>
    /// <returns>�������� �������� �������� �����.</returns>
    /// <exception cref="std::runtime_error">�������������, ���� ���� ����.</exception>
    T peek()
    {
        if (top == nullptr)
        {
            throw ("Stack is empty!");
        }
        return top->data;
    }

    /// <summary>
    /// ���������� ������� ���������� ��������� � �����.
    /// </summary>
    /// <returns>���������� ��������� � �����.</returns>
    int count() const
    {
        return counter;
    }

    /// <summary>
    /// ������� ����, ������ ��� ��������.
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