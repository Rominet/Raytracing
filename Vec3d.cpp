#include "Vec3d.hpp"

Vec3d::Vec3d()
{

}

Vec3d::Vec3d(const Matrix<double, 1, 4> m)
{
	setValues(fromHomogenous(m).getValues(), 3);
}

Vec3d::Vec3d(const Matrix<double, 1, 3> a, const Matrix<double, 1, 3> b)
{
	this->_values[0] = b.getValues()[0] - a.getValues()[0];
	this->_values[1] = b.getValues()[1] - a.getValues()[1];
	this->_values[2] = b.getValues()[2] - a.getValues()[2];
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

double Vec3d::magnitude() const
{
	return sqrt(squareMagnitude());
}

double Vec3d::squareMagnitude() const
{
	return pow(this->_values[0], 2) + pow(this->_values[1], 2) + pow(this->_values[2], 2);
}

Vec3d Vec3d::operator/=(double d)
{
	this->_values[0] /= d;
	this->_values[1] /= d;
	this->_values[2] /= d;

	return *this;
}

double Vec3d::scalarProduct(const Vec3d other) const
{
	return (*this)[0] * other[0] + (*this)[1] * other[1] + (*this)[2] * other[2];
}