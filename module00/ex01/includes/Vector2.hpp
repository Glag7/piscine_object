#ifndef VECTOR2_HPP
# define VECTOR2_HPP

#include <fstream>

struct	Vector2
{
	float	x;
	float	y;

	Vector2();
	Vector2(float x, float y);

	bool	operator==(const Vector2 &v) const;
	bool	operator>(const Vector2 &v) const;
	bool	operator<(const Vector2 &v) const;
	bool	operator>=(const Vector2 &v) const;
	bool	operator<=(const Vector2 &v) const;
	Vector2	operator+(const Vector2 &v) const;
	Vector2	operator-(const Vector2 &v) const;
};

std::ostream	&operator<<(std::ostream &o, const Vector2 &v);

#endif
