#include <stdexcept>
#include <iostream>
#include "Car.hpp"

Car::Car(unsigned gears, unsigned maxSpeed, unsigned maxAngle, unsigned maxForce) :
	engine(maxSpeed),
	transmission(gears),
	steering(maxAngle),
	brakes(engine, maxForce)
{
}

void	Car::start()
{
	engine.on();
}

void	Car::stop()
{
	engine.off();
	apply_emergency_brakes();
}

void	Car::accelerate(unsigned speed)
{
	try
	{
		engine.accelerate(speed);
	}
	catch (std::runtime_error &e)
	{
		std::cout << "Error while accelerating: " << e.what() << "\n";
	}
}

void	Car::shift_gears_up()
{
	try
	{
		transmission.up();
	}
	catch (std::runtime_error &e)
	{
		std::cout << "Error while shifting up: " << e.what() << "\n";
	}
}

void	Car::shift_gears_down()
{
	try
	{
		transmission.down();
	}
	catch (std::runtime_error &e)
	{
		std::cout << "Error while shifting down: " << e.what() << "\n";
	}
}

void	Car::reverse()
{
	transmission.reverse();
}

void	Car::turn_wheel(int angle)
{
	try
	{
		steering.turn(angle);
	}
	catch (std::runtime_error &e)
	{
		std::cout << "Error while turning: " << e.what() << "\n";
	}
}

void	Car::straighten_wheels()
{
	steering.straighten();
}

void	Car::apply_force_on_brakes(unsigned force)
{
	try
	{
		brakes.brake(force);
	}
	catch (std::runtime_error &e)
	{
		std::cout << "Error while braking: " << e.what() << "\n";
	}
}

void	Car::apply_emergency_brakes()
{
	brakes.brake(brakes.getMaxForce());
}
