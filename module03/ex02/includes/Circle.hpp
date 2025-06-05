#ifndef CIRCLE_HPP
# define CIRCLE_HPP

#include "Shape.hpp"

class Circle : public Shape
{
	private:
		double r;
	public:
		Circle(double r);
		
		double	getPerimeter() const;
		double	getArea() const;
};

#endif
