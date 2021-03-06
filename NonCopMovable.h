#ifndef NONCOPMOVABLE_H_
#define NONCOPMOVABLE_H_
#include <iostream>
#include <string>

class NonCopMovable
{
private:
	double value;
	NonCopMovable(const NonCopMovable&) = delete; // Запрет на использование конструктора копирования
	NonCopMovable& operator=(const NonCopMovable&) = delete; // Запрет на использование оператора копирования
	NonCopMovable(const NonCopMovable&&) = delete; // Запрет на использование конструктора перемещения
	NonCopMovable& operator=(const NonCopMovable&&) = delete; // Запрет на использование оператора копирования
public:
	NonCopMovable(const double value) : value(value) {}
	double & get_value() { return value; }
	friend std::ostream& operator<<(std::ostream& os, const NonCopMovable& obj)
	{
		os << obj.value << std::endl;
		return os;
	}

};
#endif