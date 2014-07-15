#pragma once

#include "Vec3d.hpp"
#include "Point3d.hpp"
#include "Transform.h"

class Ray
{
private:
	Point3d origin;
	Vec3d direction;

public:
	Ray(void);
	Ray(const Point3d origin, const Vec3d direction);
	~Ray(void);

	Point3d getOrigin() const;
	Vec3d getDirection() const;

	Ray getLocalRay(const Transform transform) const;
};

