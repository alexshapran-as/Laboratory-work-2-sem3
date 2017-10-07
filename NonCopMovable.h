#ifndef NONCOPMOVABLE_H_
#define NONCOPMOVABLE_H_
#include <iostream>
#include <string>

class NonCopMovable
{
private:
	double value;
	NonCopMovable(const NonCopMovable&) = delete; // ������ �� ������������� ������������ �����������
	NonCopMovable& operator=(const NonCopMovable&) = delete; // ������ �� ������������� ��������� �����������
	NonCopMovable(const NonCopMovable&&) = delete; // ������ �� ������������� ������������ �����������
	NonCopMovable& operator=(const NonCopMovable&&) = delete; // ������ �� ������������� ��������� �����������
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