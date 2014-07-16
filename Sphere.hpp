#pragma once

#include "Shape.hpp"

class Sphere : public Shape 
{
private:
	double radius;

public:
	Sphere();
	Sphere(double radius);
	~Sphere();

	double getRadius() const;

	bool isRayIntersecting(const Ray ray, Point3d &intersectPoint, Vec3d &intersectNormal) const;
};

