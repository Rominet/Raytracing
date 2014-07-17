#pragma once
#include "matrix.hpp"
#include "Point3d.hpp"

class Vec3d : public Matrix<double, 1, 3>
{
public:
	Vec3d();
	Vec3d(const Matrix<double, 1, 3> &a, const Matrix<double, 1, 3> &b);
	Vec3d(double x, double y, double z);
	Vec3d(const Matrix<double, 4, 1> &m);
	~Vec3d(void);
	
	Vec3d normalize();
	double magnitude() const;
	double squareMagnitude() const;

	double scalarProduct(const Vec3d &other) const;

	Vec3d operator/=(double d);
	double operator[](int pos) const { return _values[pos]; }
	double & operator[](int pos) { return _values[pos]; }
};

