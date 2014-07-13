#pragma once

#include "Vec3d.hpp"

class Ray
{
private:
	Vec3d origin;
	Vec3d direction;

public:
	Ray(void);
	Ray(Vec3d origin, Vec3d direction);
	~Ray(void);
};

