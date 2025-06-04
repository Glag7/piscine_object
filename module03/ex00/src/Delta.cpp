#include "Delta.hpp"

Delta::Delta()
{
	prevTime = std::chrono::steady_clock::now();
	delta = 0.;
}

Delta	&Delta::getInstance()
{
	static Delta	delta;

	return delta;
}

double	Delta::updateDelta()
{
	std::chrono::steady_clock::time_point currTime = std::chrono::steady_clock::now();

	delta = std::chrono::duration_cast<std::chrono::microseconds>(currTime - prevTime).count();
	return delta;
}
