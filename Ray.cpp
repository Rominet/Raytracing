#include "Ray.hpp"
#include "Vec3d.hpp"

Ray::Ray(void)
{
}

Ray::Ray(const Point3d origin, const Vec3d direction)
{
	this->origin = Point3d(origin);
	this->direction = Vec3d(direction);
}

Ray::~Ray(void)
{
	std::cout << "delete Ray" << std::endl;
}

Point3d Ray::getOrigin() const
{
	return this->origin;
}

Vec3d Ray::getDirection() const
{
	return this->direction;
}

Ray Ray::getLocalRay(Transform transform) const
{
	Matrix<double, 1, 4> localOrig = toHomogenous(this->getOrigin());
	Matrix<double, 1, 4> localDir = toHomogenous(this->getDirection());

	localOrig *= *transform.getTransformationInv();
	localDir *= *transform.getTransformationInv();

	return Ray(Point3d(localOrig), Vec3d(localDir));
}