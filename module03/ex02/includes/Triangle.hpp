#ifndef TRIANGLE_HPP
# define TRIANGLE_HPP

#include "Shape.hpp"

class Triangle : public Shape
{
	private:
		double a, b, c;
	public:
		Triangle(double a, double b, double c);
		
		double	getPerimeter() const;
		double	getArea() const;
};

#endif
