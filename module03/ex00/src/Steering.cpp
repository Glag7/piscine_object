#include "Steering.hpp"
#include <stdexcept>
#include <iostream>

Steering::Steering(unsigned maxAngle) : maxAngle(maxAngle)
{
}

void	Steering::straighten()
{
	angle = 0;
	std::cout << "Straightening wheels\n";
}

void	Steering::turn(int angle)
{
	if ((angle > 0 && static_cast<unsigned>(angle) > maxAngle)
		|| (angle < 0 && -static_cast<unsigned>(angle) > maxAngle))
		throw std::runtime_error("Can't turn that much");
	std::cout << "Turning wheels to " << angle << " degrees\n";
}
