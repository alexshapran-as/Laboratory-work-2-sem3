#include "stdafx.h"
#include "NonCopMovable.h"
#include <iostream>
#include <string>
#include <utility>
const unsigned int size = { 10 }; // Размер стека

template <class T>
class Stack_t
{
private:
	T items[size]; // Массив для хранения элементов
	int top; // индекс вершины стека
	Stack_t<T>(const Stack_t<T>&) = delete;
	Stack_t<T>& operator=(const Stack_t<T>&) = delete;
public:
	Stack_t();
	T get_item() { return items[top]; }
	bool push(const T& item);
	bool pop();
	void pop_emplace(T&&);
	T& head();
	void pop_destroy();

	friend std::ostream& operator<<(std::ostream& out, const Stack_t<T>& st)
	{
		for (int i = { st.top - 1 }; i >= 0; --i)
			out << st.items[i] << std::endl;
		out << std::endl;
		return out;
	}
};

int main()
{
	system("chcp 65001");
	using std::cout;
	using std::cin;
	using std::endl;
	using std::move;
	using std::string;

	cout << endl << "Лабораторная работа №2 : R - value ссылки, семантика перемещения" << endl 
	<< "Реализация некопируемых и неперемещаемых объектов!";
	double val = { 66.6 };
	NonCopMovable obj1(val);
	cout << endl << "Некопируемый и неперемещаемый объект со значением " << obj1 << endl;
	//NonCopMovable obj2(obj1);
	//NonCopMovable obj3 = obj1;
	//NonCopMovable obj4(move(obj1));
	//NonCopMovable obj5 = move(obj1);
	cout << "Реализация класса stack, хранящего до 10 элементов и работающего с обычными элементами (q - для выхода):" << endl
		<< "1. Добавить элемент в стек;" << endl << "2. Удалить элемент из стека;" << endl
		<< "3. Показать элементы стека." << endl
		<< "Реализация класса stack, хранящего до 10 элементов и работающего с некопируемыми неперемещаемыми объектами:"
		<< endl << "4. Добавить элемент в стек; " << endl << "5. Получить ссылку на верхушку стека;" 
		<< endl << "6. Разрушить верхушку стека." << endl;
	Stack_t<double> st;
	double temp = { 0.0 };
	unsigned int choice = { 0 };
	while (cin >> choice)
	{
		if (choice == 1)
		{
			cout << "Введите элемент для вставки: ";
			if (cin >> temp && st.push(temp) == true);
			else
				cout << "Стек полон!" << endl << endl;
		}
		else if (choice == 2)
		{
			cout << "Удаление элемента из стека";
			if (st.pop() == true)
				cout << endl << "Верхний элемент стека: " << st.get_item() << endl << endl;
			else
				cout << endl << "Стек пуст!" << endl;
		}
		else if (choice == 3)
			cout << "Элементы стека: " << endl << st;
		else if (choice == 4)
		{
			cout << "Введите элемент для вставки: ";
			cin >> obj1.get_value();
			st.pop_emplace(std::move(obj1.get_value()));
		}
		else if (choice == 5)
		{
			cout << endl << "В вершине стека находится элемент: " << st.head();
			cin.get();
			cout << endl << "Желаете изменить значение этого элемента (y/n)? ";
			char ch;
			cin.get(ch);
			if (ch == 'y')
			{
				cout << "Введите новое значение для элемента: "; 
				cin >> st.head();
			}
		}
		else if (choice == 6)
		{
			st.pop_destroy();
		}
		cout << "Реализация класса stack, хранящего до 10 элементов (q - для выхода):" << endl
			<< "1. Добавить элемент в стек;" << endl << "2. Удалить элемент из стека;" << endl
			<< "3. Показать элементы стека;" <<  endl << "Реализация класса stack, хранящего до 10 элементов" 
			"и работающего с некопируемыми неперемещаемыми объектами:"
			<< endl << "4. Добавить элемент в стек; " << endl << "5. Получить ссылку на верхушку стека;"
			<< endl << "6. Разрушить верхушку стека." << endl;
	}

	return 0;
}

template <class T>
Stack_t<T>::Stack_t()
{
	top = { 0 };
}
template <class T>
bool Stack_t<T>::push(const T& item)
{
	if (top < size)
	{
		items[top++] = item;
		return true;
	}
	else
		false;
}
template <class T>
bool Stack_t<T>::pop()
{
	if (top > 0)
	{
		--top;
		return true;
	}
	else
		false;
}

template <class T>
void Stack_t<T>::pop_emplace(T&& arg)
{
	items[top - 1] = std::forward<T>(arg);
}

template <class T>
T& Stack_t<T>::head()
{
	return items[top-1];
}

template <class T>
void Stack_t<T>::pop_destroy()
{
	items[top-1] = 0;
	top--;
}