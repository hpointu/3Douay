#include "Vector2d.hpp"
#include <cmath>

Vector2d::Vector2d()
	: x(0), y(0)
{
}

Vector2d::Vector2d(double x, double y)
	: x(x), y(y)
{

}

Vector2d::Vector2d(const Vector2d &v)
	: x(v.x), y(v.y)
{

}

Vector2d operator+(const Vector2d &u, const Vector2d &v)
{
	Vector2d r(u);
	r.x += v.x;
	r.y += v.y;
	return r;
}

Vector2d operator-(const Vector2d &u, const Vector2d &v)
{
	Vector2d r(u);
	r.x -= v.x;
	r.y -= v.y;
	return r;
}

double Vector2d::length() const
{
	return sqrt( (x*x) + (y*y) );
}

void Vector2d::normalize()
{
	double n = length();
	x /= n;
	y /= n;
}
