#pragma once

#include "Matrix.hpp"
#include "Ray.hpp"
#include "Vec3d.hpp"

class Shape
{
private:
	Matrix<double, 1, 3> ambiant_coeff;
	Matrix<double, 1, 3> difuse_coeff;
	Matrix<double, 1, 3> specular_coeff;
	Vec3d center;

public:
	Shape(void);
	~Shape(void);
	virtual bool isRayIntersecting(const Ray ray, Vec3d &intersectPoint, Vec3d &intersectNormal) = 0;
};

