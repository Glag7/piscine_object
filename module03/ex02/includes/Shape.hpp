#ifndef SHAPE_HPP
# define SHAPE_HPP

class Shape
{
	public:
		virtual ~Shape() {};

		virtual double	getPerimeter() const = 0;
		virtual double	getArea() const = 0;
};

#endif
