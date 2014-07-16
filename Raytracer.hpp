#pragma once
#include <stdlib.h>
#include <fstream>
#include "Scene.hpp"
#include "Ray.hpp"
#include "Color.hpp"


class Raytracer
{
private:
	Scene scene;
	int depth;

	double nbRayonsLances;

	// Final image and dimensions
	int width, height;
	unsigned char *image;

	void launchRays(double x, double y, Color &color);
	void launchRay(Ray ray, int depth, Color &color);
	Ray createRay(double h, double w);
	bool calcIntersect(Ray r, Point3d &intersectPoint, Vec3d &normalIntersect, int &numShape);
	Color calcAmbiantLight(Shape *shape, Point3d intersectPoint) const;

public:
	Raytracer(Scene s);
	~Raytracer();

	void renderScene();
	void saveScene(char *fileName);
};

