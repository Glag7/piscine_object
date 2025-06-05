#include "Rectangle.hpp"

Rectangle::Rectangle(double w, double h) : 
	w(w),
	h(h)
{
}

double	Rectangle::getPerimeter() const
{
	return 2 * (w + h);
}

double	Rectangle::getArea() const
{
	return w * h;
}
