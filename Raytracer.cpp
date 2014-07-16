#define _USE_MATH_DEFINES
#include "Raytracer.hpp"
#include "Camera.hpp"
#include <math.h>
#include <cmath> 

Raytracer::Raytracer(Scene s) : scene(s)
{
	width = scene.getCamera().getWidth();
	height = scene.getCamera().getHeight();

	// Assign image
	image = new unsigned char[3 * width * height];
}


Raytracer::~Raytracer()
{
	delete image;
}


void Raytracer::saveScene(char *fileName)
{

	std::ofstream of(fileName, std::ios::out | std::ios::binary);
	int h, w, rgb;
	int maxComposante = 255;

	std::cout << std::endl << "Saving scene in : " << fileName;

	of << "P6" << std::endl;
	of << width << " " << height << std::endl;
	of << maxComposante << std::endl;
	for(h = 0; h < height; h++)
	{
		for(w = 0; w < width; w++)
		{
			for(rgb = 0; rgb < 3; rgb++)
			{
				of << image[((height - h - 1) * width + w) * 3 + rgb];
			}
		}
	}

	of.close();
	std::cout << "Save completed" << std::endl;
}

void Raytracer::renderScene()
{
	int h, w;
	double invWidth = 1 / double(width);
	double invHeight = 1 / double(height);
	Color color;
	
	double fov = 30, aspectratio = width / double(height);
	double angle = tan(M_PI * 0.5 * fov / double(180));

	std::cout << "Rendering scene ..." << std::endl;
	
	// Raytracing
	for (h = 0; h < height; h++)
	{
		for (w = 0; w < width; w++)
		{
			double xx = (2 * ((h + 0.5) * invWidth) - 1) * angle * aspectratio;
			double yy = (1 - 2 * ((w + 0.5) * invHeight)) * angle;
			launchRays(xx, yy, color);
			unsigned char r = color.getRedUC();
			unsigned char b = color.getBlueUC();
			unsigned char g = color.getGreenUC();

			image[h * 3 * width + w * 3] = color.getRedUC();
			image[h * 3 * width + w * 3 + 1] = color.getGreenUC();
			image[h * 3 * width + w * 3 + 2] = color.getBlueUC();
		}
		//std::cout << "\tLine " << h << " rendered" << std::endl;
	}

	std::cout << "Rendering over!" << std::endl;
}

void Raytracer::launchRays(double h, double w, Color &color)
{
	Ray ray = createRay(h, w);
	launchRay(ray, 1, color);
}

Ray Raytracer::createRay(double h, double w)
{
	Camera c = scene.getCamera();
	Point3d pos;
	Vec3d dir;

	if (c.getProjectType() == CamProjectionType::PERSPECTIVE)
	{
		dir = Vec3d(w, h, 1.0);
		dir.normalize();
	}
	else
	{
		pos = Point3d(w, h, 0.0);
		dir = Vec3d(0.0, 0.0, 1.0);
	}

	return Ray(pos, dir);
}

void Raytracer::launchRay(Ray ray, int depth, Color &color)
{
	Point3d intersect;
	Vec3d normal;
	int numShape;
	
	//std::cout << ray.getDirection() << std::endl;

	if (depth > 0)
	{
		if (calcIntersect(ray, intersect, normal, numShape))
		{
			color = calcAmbiantLight(scene.getShapes()[numShape], intersect);
		}
	}
}

/* calcule l'intersection la plus proche entre le rayon r et la scene s */
bool Raytracer::calcIntersect(Ray ray, Point3d &intersectPoint, Vec3d &normalIntersect, int &num)
{
	Point3d zero;
	Point3d intersect;
	Vec3d normal;
	bool foundIntersection = false;

	for (unsigned int numShape = 0; numShape < scene.getShapes().size(); numShape++)
	{
		Shape *shape = scene.getShapes()[numShape];
		if (shape->isRayIntersecting(ray, intersect, normal))
		{
			if (!foundIntersection || (foundIntersection && (Vec3d(zero, intersectPoint).squareMagnitude() > Vec3d(zero, intersect).squareMagnitude())))
			{
				intersectPoint = Point3d(intersect);
				normalIntersect = Vec3d(normal);
				num = numShape;
			}
			foundIntersection = true;
		}
	}
	return foundIntersection;
}

Color Raytracer::calcAmbiantLight(Shape *shape, Point3d intersectPoint) const
{
	Color objColor = shape->getAmbiantColor(intersectPoint);

	return (objColor * scene.getAmbiantColor());
}