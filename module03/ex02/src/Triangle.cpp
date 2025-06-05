#include <cmath>
#include "Triangle.hpp"

Triangle::Triangle(double a, double b, double c) :
	a(a),
	b(b),
	c(c)
{
}

double	Triangle::getPerimeter() const
{
	return a + b + c;
}

double	Triangle::getArea() const
{
	double	halfp = getPerimeter() * .5;

	return std::sqrt(halfp * (halfp - a) * (halfp - b) * (halfp - c)) ;
}

