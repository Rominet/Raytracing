#include "Shape.hpp"

Shape::Shape(void)
{
	transform = new Transform();
}


Shape::~Shape(void)
{
	delete transform;
	std::cout << "Delete Transform" << std::endl;
}

Color Shape::getAmbiantColor(Point3d intersect) const
{
	return Color(ambiant_coeff[0], ambiant_coeff[1], ambiant_coeff[2]);
}

void Shape::setTransform(Vec3d position, Vec3d rotation, Vec3d scale)
{
	this->transform->setPosition(position);
	this->transform->setRotation(rotation);
	this->transform->setScale(scale);
}