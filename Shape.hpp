#pragma once

#include "Matrix.hpp"
#include "Ray.hpp"
#include "Vec3d.hpp"
#include "Point3d.hpp"
#include "Transform.h"
#include "Color.hpp"

class Shape
{
private:
	Vec3d ambiant_coeff;
	Vec3d diffuse_coeff;
	Vec3d specular_coeff;
	Transform transform;

public:
	Shape(void);
	~Shape(void);
	
	Vec3d getAmbiantCoeff() const { return this->ambiant_coeff; }
	Vec3d getDifuseCoeff() const { return this->diffuse_coeff; }
	Vec3d getSpecularCoeff() const { return this->specular_coeff; }
	Transform getTransform() const { return this->transform; }

	virtual bool isRayIntersecting(const Ray ray, Point3d &intersectPoint, Vec3d &intersectNormal) = 0;

	Color getAmbiantColor(Point3d intersect) const;
};

