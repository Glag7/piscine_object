#include <cmath>
#include "Circle.hpp"

Circle::Circle(double r) : r(r)
{
}

double	Circle::getPerimeter() const
{
	return 2 * M_PI * r;
}

double	Circle::getArea() const
{
	return M_PI * r * r;
}
