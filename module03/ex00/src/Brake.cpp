#include <stdexcept>
#include <iostream>
#include "Brake.hpp"
#include "Engine.hpp"

Brake::Brake(Engine &engine, unsigned maxForce) :
	engine(engine),
	maxForce(maxForce)
{
}

void	Brake::brake(unsigned force)
{
	if (force > maxForce)
		throw std::runtime_error("force is too high");
	std::cout << "Braking by " << force << "\n";
	engine.slow_down(force);
}
