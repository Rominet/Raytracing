#include "Parallelogram.hpp"


Parallelogram::Parallelogram(Vec3d topLeft, Vec3d topRight, Vec3d botRight, Vec3d botLeft)
{
	this->botLeft = Vec3d(topLeft);
	this->topLeft = Vec3d(topRight);
	this->botRight = Vec3d(botRight);
	this->botLeft = Vec3d(botLeft);
}

Parallelogram::~Parallelogram()
{
}

bool Shape::isRayIntersecting(const Ray ray, Vec3d &intersectPoint, Vec3d &intersectNormal)
{
	double distance;
	Vec3d p[4];

	Vec3d pos;
	Vec3d dir;
	Vec3d pos2;
	Vec3d dir2;
	pos = ray.getOrigin();
	dir = ray.getDirection();
}