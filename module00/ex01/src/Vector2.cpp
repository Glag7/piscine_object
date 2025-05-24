#include "Vector2.hpp"

Vector2::Vector2() : x(0), y(0)
{
}

Vector2::Vector2(float x, float y) : x(x), y(y)
{
}

bool	Vector2::operator==(const Vector2 &v) const
{
	return y == v.y && x == v.x; 
}

bool	Vector2::operator>(const Vector2 &v) const
{
	return y > v.y || (y == v.y && x > v.x);
}

bool	Vector2::operator<(const Vector2 &v) const
{
	return y < v.y || (y == v.y && x < v.x);
}

bool	Vector2::operator>=(const Vector2 &v) const
{
	return y >= v.y || (y == v.y && x >= v.x);
}

bool	Vector2::operator<=(const Vector2 &v) const
{
	return y <= v.y || (y == v.y && x <= v.x);
}

Vector2	Vector2::operator+(const Vector2 &v) const
{
	return Vector2(x + v.x, y + v.y);
}

Vector2	Vector2::operator-(const Vector2 &v) const
{
	return Vector2(x - v.x, y - v.y);
}

std::ostream	&operator<<(std::ostream &o, const Vector2 &v)
{
	o << "(" << v.x << ", " << v.y << ")";
	return o;
}
