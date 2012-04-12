#ifndef EVECTOR2_HPP
#define EVECTOR2_HPP

class Vector2d
{
public:
	Vector2d();
	Vector2d(double x, double y);
	Vector2d(const Vector2d& v);

	double x;
	double y;

	double length() const;
	void normalize();
};

Vector2d operator+(const Vector2d &v);
Vector2d operator-(const Vector2d &v);

#endif // EVECTOR2_HPP
