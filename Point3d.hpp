#pragma once
#include "Matrix.hpp"

class Point3d : public Matrix<double, 1, 3>
{
public:
	Point3d();
	Point3d(const Matrix<double, 4, 1>);
	Point3d(double x, double y, double z);
	~Point3d();
};

