#pragma once

#include "Vec3d.hpp"
#include "Point3d.hpp"
#include "Transform.hpp"

class Ray
{
private:
	Point3d origin;
	Vec3d direction;

public:
	Ray();
	Ray(Point3d origin, Vec3d direction);
	Ray(const Ray &r);
	~Ray();

	Point3d getOrigin() const;
	Vec3d getDirection() const;

	Ray getLocalRay(Transform transform) const;
};

