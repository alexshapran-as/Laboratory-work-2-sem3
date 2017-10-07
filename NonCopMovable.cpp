#include "NonCopMovable.h"
#include <iostream>
#include <string>

std::ostream& operator<<(std::ostream& os, const NonCopMovable& obj)
{
	os << std::endl << obj.str << std::endl;
	return os;
}
