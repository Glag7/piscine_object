#include <stdexcept>
#include <iostream>
#include "Engine.hpp"

Engine::Engine(double maxSpeed) :
	maxSpeed(maxSpeed),
	speed(0),
	running(false)
{
}

void	Engine::accelerate(unsigned speed)
{
	if (!running)
		throw std::runtime_error("engine is off");
	if (speed > maxSpeed)
		throw std::runtime_error("speed is too high");
	this->speed += speed;
	std::cout << "Speed increased by " << speed << " now at " << this->speed << "\n";
}
void	Engine::slow_down(unsigned speed)
{
	if (this->speed < speed)
		this->speed = 0;
	else
		this->speed -= speed;
	std::cout << "Speed slowed down by " << speed << " now at " << this->speed << "\n";
}

void	Engine::on()
{
	running = true;
	std::cout << "Turning engine on\n";
}

void	Engine::off()
{
	running = false;
	std::cout << "Turning engine off\n";
}
