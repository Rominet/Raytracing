#include "Vec3d.hpp"

Vec3d::Vec3d(void)
{
}


Vec3d::Vec3d(double x, double y, double z)
{
	this->_values[0] = x;
	this->_values[1] = y;
	this->_values[2] = z;
}


Vec3d::~Vec3d(void)
{
}

Vec3d Vec3d::normalize()
{
	return (*this /= magnitude());
}

double Vec3d::magnitude()
{
	return sqrt(pow(this->_values[0], 2) + pow(this->_values[1], 2) + pow(this->_values[2], 2));
}


Vec3d Vec3d::operator/=(double d)
{
	this->_values[0] / d;
	this->_values[1] / d;
	this->_values[2] / d;

	return *this;
}