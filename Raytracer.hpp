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

	void launchRays(int x, int y, Color &color);
	void launchRay(Ray ray, int depth, Color &color);
	Ray createRay(int h, int w) const;
	bool calcIntersect(Ray r, Point3d &intersectPoint, Vec3d &normalIntersect, Shape *shape);
	Color calcAmbiantLight(Shape *shape, Point3d intersectPoint) const;

public:
	Raytracer(Scene s);
	~Raytracer();

	Scene getScene() const { return scene; }

	void renderScene();
	void saveScene(char *fileName);
};

