#pragma once
#include "matrix.hpp"
class Vec3d : public Matrix<double, 1, 3>
{
public:
	Vec3d(void);
	Vec3d(double x, double y, double z);
	~Vec3d(void);
	
	Vec3d normalize();
	double magnitude();

	Vec3d operator/=(double d);
};

