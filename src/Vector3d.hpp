#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3d
{
public:
	double x;
	double y;
	double z;

	Vector3d();
	Vector3d(double x,double y,double z);
	Vector3d(const Vector3d & v);
	Vector3d(const Vector3d & from,const Vector3d & to);

	Vector3d & operator= (const Vector3d & v);

	Vector3d & operator+= (const Vector3d & v);
	Vector3d operator+ (const Vector3d & v) const;

	Vector3d & operator-= (const Vector3d & v);
	Vector3d operator- (const Vector3d & v) const;

	Vector3d & operator*= (const double a);
	Vector3d operator* (const double a)const;
	friend Vector3d operator* (const double a,const Vector3d & v);

	Vector3d & operator/= (const double a);
	Vector3d operator/ (const double a)const;

	Vector3d crossProduct(const Vector3d & v)const;
    double length()const;
	Vector3d & normalize();
};

#endif //VECTOR3D_H
