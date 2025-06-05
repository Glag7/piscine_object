#include <iostream>
#include "Triangle.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"

void	yes(Shape *s)
{
	std::cout << "perimeter " << s->getPerimeter() << "\n";
	std::cout << "area " << s->getArea() << "\n";
}

int	main()
{
	Circle		c(3);
	Triangle	t(3, 4, 5);
	Rectangle	r(4, 5);

	yes(&c);
	yes(&t);
	yes(&r);
}
