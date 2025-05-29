#include "Shovel.hpp"

Shovel::Shovel() : Tool("Shovel", 3)
{
	std::cout << "Shovel constructor.\n";
}

void	Shovel::use()
{
	std::cout << "Using shovel.\n";
}
