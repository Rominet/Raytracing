#pragma once
#include "Shape.hpp"

class Parallelogram : public Shape
{
	private:
		Vec3d topLeft;
		Vec3d topRight;
		Vec3d botLeft;
		Vec3d botRight;


	public:
		Parallelogram(Vec3d topLeft, Vec3d topRight, Vec3d botRight, Vec3d botLeft);
		~Parallelogram();
};

