#include "Shape.hpp"

Shape::Shape(void)
{
	transform = new Transform();
	ambiant_coeff = new Vec3d();
	specular_coeff = new Vec3d();
	diffuse_coeff = new Vec3d();
}


Shape::~Shape(void)
{

}

Color Shape::getAmbiantColor(Point3d intersect) const
{
	Vec3d coeff = *ambiant_coeff;
	return Color(coeff[0], coeff[1], coeff[2]);
}

void Shape::setTransform(Vec3d position, Vec3d rotation, Vec3d scale)
{
	this->transform->setPosition(position);
	this->transform->setRotation(rotation);
	this->transform->setScale(scale);
}