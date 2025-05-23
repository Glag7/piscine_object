#ifndef VECTOR2_HPP
# define VECTOR2_HPP

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
};

#endif
