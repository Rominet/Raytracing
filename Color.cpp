#include "Color.hpp"


Color::Color()
{
	this->red = 0;
	this->green = 0;
	this->blue = 0;
}

Color::Color(double red, double green, double blue)
{
	this->red = red;
	this->green = green;
	this->blue = blue;
}

Color::~Color()
{
}

Color Color::operator*(const Color other) const
{
	Color tmp;
	tmp.setRed(this->getRed() * other.getRed());
	tmp.setGreen(this->getGreen() * other.getGreen());
	tmp.setBlue(this->getBlue() * other.getBlue());
	return tmp;
}