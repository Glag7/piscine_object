#ifndef RECTANGLE_HPP
# define RECTANGLE_HPP

#include "Shape.hpp"

class Rectangle : public Shape
{
	private:
		double w, h;
	public:
		Rectangle(double w, double h);
		
		double	getPerimeter() const;
		double	getArea() const;
};

#endif
