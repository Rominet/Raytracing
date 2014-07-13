#include "Ray.hpp"
#include "Vec3d.hpp"

Ray::Ray(void)
{

}

Ray::Ray(const Vec3d origin, const Vec3d direction)
{
	this->origin = Vec3d(origin);
	this->direction = Vec3d(direction);
}

Ray::~Ray(void)
{
}
