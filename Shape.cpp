#include "Shape.hpp"

Shape::Shape(void)
{
}


Shape::~Shape(void)
{
}

Color Shape::getAmbiantColor(Point3d intersect) const
{
	return Color(ambiant_coeff[0], ambiant_coeff[1], ambiant_coeff[2]);
}