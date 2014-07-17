#include "Point3d.hpp"

Point3d::Point3d()
{

}

Point3d::Point3d(const Matrix<double, 4, 1> &m)
{
	setValues(fromHomogenous(m).getValues(), 3);
}

Point3d::Point3d(double x, double y, double z)
{
	this->_values[0] = x;
	this->_values[1] = y;
	this->_values[2] = z;
}

Point3d::~Point3d()
{
}