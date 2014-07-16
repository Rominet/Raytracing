#include "Ray.hpp"
#include "Vec3d.hpp"

Ray::Ray()
{
}

Ray::Ray(Point3d origin, Vec3d direction)
{
	this->origin.setValues(origin);
	this->direction.setValues(direction);
}

Ray::Ray(const Ray &r)
{
	this->origin.setValues(r.origin);
	this->direction.setValues(r.direction);
}

Ray::~Ray()
{
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

	localOrig *= transform.getTransformationInv();
	localDir *= transform.getTransformationInv();

	return Ray(Point3d(localOrig), Vec3d(localDir));
}