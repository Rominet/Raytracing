#pragma once

#include "Shape.hpp"

class Sphere : public Shape 
{
private:
	double radius;

public:
	Sphere(void);
	~Sphere(void);
};

