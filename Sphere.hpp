#pragma once

#include "Shape.hpp"

class Sphere : public Shape 
{
private:
	double radius;

public:
	Sphere(void);
	Sphere(double radius);
	~Sphere(void);

	double getRadius() const;

	bool isRayIntersecting(const Ray ray, Point3d &intersectPoint, Vec3d &intersectNormal) const;
};

