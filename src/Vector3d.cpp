#include "Vector3d.hpp"
#include <cmath>

Vector3d::Vector3d()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3d::Vector3d(double x,double y,double z) :
	x(x), y(y), z(z)
{
}

Vector3d::Vector3d(const Vector3d & v)
{
	x = v.x;
	y = v.y;
	z = v.z;
}

Vector3d::Vector3d(const Vector3d & from,const Vector3d & to)
{
	x = to.x - from.x;
	y = to.y - from.y;
	z = to.z - from.z;
}

Vector3d & Vector3d::operator= (const Vector3d & v)
{
	x = v.x;
	y = v.y;
	z = v.z;
    return *this;
}

Vector3d & Vector3d::operator+= (const Vector3d & v)
{
	x += v.x;
	y += v.y;
	z += v.z;
    return *this;
}

Vector3d Vector3d::operator+ (const Vector3d & v) const
{
	Vector3d t = *this;
    t += v;
    return t;
}

Vector3d & Vector3d::operator-= (const Vector3d & v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
    return *this;
}

Vector3d Vector3d::operator- (const Vector3d & v) const
{
	Vector3d t = *this;
    t -= v;
    return t;
}

Vector3d & Vector3d::operator*= (const double a)
{
	x *= a;
	y *= a;
	z *= a;
    return *this;
}

Vector3d Vector3d::operator* (const double a)const
{
	Vector3d t = *this;
    t *= a;
    return t;
}

Vector3d operator* (const double a,const Vector3d & v)
{
	return Vector3d(v.x*a,v.y*a,v.z*a);
}

Vector3d & Vector3d::operator/= (const double a)
{
	x /= a;
	y /= a;
	z /= a;
    return *this;
}

Vector3d Vector3d::operator/ (const double a)const
{
	Vector3d t = *this;
    t /= a;
    return t;
}

Vector3d Vector3d::crossProduct(const Vector3d & v)const
{
	Vector3d t;
	t.x = y*v.z - z*v.y;
	t.y = z*v.x - x*v.z;
	t.z = x*v.y - y*v.x;
    return t;
}

double Vector3d::length()const
{
	return sqrt( x*x + y*y + z*z);
}

Vector3d & Vector3d::normalize()
{
    (*this) /= length();
    return (*this);
}


