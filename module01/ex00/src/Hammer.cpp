#include "Hammer.hpp"

Hammer::Hammer() : Tool("hammer", 2)
{
	std::cout << "Hammer constructor.\n";
}

void	Hammer::use()
{
	std::cout << "Using hammer.\n";
}
