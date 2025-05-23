#include "Vector2.hpp"

Vector2::Vector2() : x(0), y(0)
{
}

Vector2::Vector2(float x, float y) : x(x), y(y)
{
}

bool	Vector2::operator==(const Vector2 &v) const
{
	return x == v.x && y == v.y; 
}

bool	Vector2::operator>(const Vector2 &v) const
{
	return x > v.x || (x == v.x && y > v.y);
}

bool	Vector2::operator<(const Vector2 &v) const
{
	return x < v.x || (x == v.x && y < v.y);
}

bool	Vector2::operator>=(const Vector2 &v) const
{
	return x >= v.x || (x == v.x && y >= v.y);
}

bool	Vector2::operator<=(const Vector2 &v) const
{
	return x <= v.x || (x == v.x && y <= v.y);
}

