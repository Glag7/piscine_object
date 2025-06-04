#include <iostream>
#include <stdexcept>
#include "Transmission.hpp"

Transmission::Transmission(unsigned n) : nGears(n), currentGear(0)
{
}

void	Transmission::up()
{
	if (currentGear > 0 && static_cast<unsigned>(currentGear) == nGears)
		throw std::runtime_error("already on highest gear");
	currentGear += currentGear == -1;
	std::cout << "Shifting up to gear " << ++currentGear << "\n";
}

void	Transmission::down()
{
	if (currentGear == -1)
		throw std::runtime_error("already in reverse");
	if (currentGear == 1)
		throw std::runtime_error("already on lowest gear");
	std::cout << "Shifting down to gear" << --currentGear << "\n";
}

void	Transmission::reverse()
{
	currentGear = -1;
	std::cout << "Shifting to reverse\n";
}
