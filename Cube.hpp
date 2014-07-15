#pragma once
#include "Shape.hpp"

class Cube : public Shape
{

private:
	double edge;
	//parallelogram * lesFaces[6];
	int faceIntersectee;

public:
	Cube(double edge);
	~Cube();
};

