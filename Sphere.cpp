#include "Sphere.hpp"
#include "Shape.hpp"
#include "Vec3d.hpp"

Sphere::Sphere() : Shape()
{
	this->radius = 1.0;
}

Sphere::Sphere(double radius)
{
	this->radius = radius;
}


Sphere::~Sphere()
{
}

double Sphere::getRadius() const
{
	return radius;
}

bool Sphere::isRayIntersecting(const Ray ray, Point3d &intersectPoint, Vec3d &intersectNormal) const
{
	Ray localRay = ray.getLocalRay(getTransform());
	Point3d localCenter;

	double OH = Vec3d(localRay.getOrigin(), localCenter).scalarProduct(localRay.getDirection());
	if (OH < 0)
		return false;
	
	double R² = pow(this->getRadius(), 2);
	double CH² = Vec3d(localRay.getOrigin(), localCenter).squareMagnitude() - pow(OH, 2);
	if (CH² > R²)
		return false;

	double d² = R² - CH²;

	// Calculate tmin
	double t1 = OH + sqrt(d²);
	double t2 = OH - sqrt(d²);
	double tmin;

	if (t1 > 0 && t2 > 0)
		tmin = fmin(t1, t2);
	else if (t1 > 0)
		tmin = t1;
	else if (t2 > 0)
		tmin = t2;
	else
		return false;

	// Find intersection point
	Matrix<double, 1, 3> dirMultTmin = localRay.getDirection() * tmin;
	Matrix<double, 1, 3> localIntersectPoint = localRay.getOrigin() + dirMultTmin;
	Matrix<double, 4, 4> transformation = getTransform().getTransformation();

	intersectPoint = toHomogenous(localIntersectPoint) * transformation;
	intersectNormal = toHomogenous(Vec3d(getTransform().getPosition(), intersectPoint).normalize()) * transformation;
	return true;
}