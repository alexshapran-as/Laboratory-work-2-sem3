#include "NonCopMovable.h"
#include <iostream>
#include <string>

NonCopMovable::NonCopMovable(const std::string _str) : str(_str) {}
std::ostream& operator<<(std::ostream& os, const NonCopMovable& obj)
{
	os << std::endl << obj.str << std::endl;
	return os;
}
