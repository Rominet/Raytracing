#include "Raytracer.hpp"
#include "Camera.hpp"

Raytracer::Raytracer(Scene *s)
{
	this->scene = s;
}


Raytracer::~Raytracer()
{
	delete image;
}


void Raytracer::saveScene(char *fileName)
{

	std::ofstream of(fileName);
	int h, w, rgb;
	int maxComposante = 255;

	std::cout << std::endl << "Saving scene in : " << fileName;

	of << "P6" << std::endl;
	of << width << " " << height << std::endl;
	of << maxComposante << std::endl;
	for (h = 0; h < height; h++)
		for (w = 0; w < width; w++)
			for (rgb = 0; rgb < 3; rgb++)
				of << image[((height - h - 1) * width + w) * 3 + rgb];

	of.close();
	delete image;
	std::cout << "Save completed" << std::endl;
}

void Raytracer::renderScene()
{
	int h, w;
	Color color;

	std::cout << "Rendering scene ..." << std::endl;

	width = scene->getCamera()->getWidth();
	height = scene->getCamera()->getHeight();

	// Assign image
	image = new unsigned char[3 * width * height];
	
	// Raytracing
	for (h = 0; h < height; h++)
	{
		for (w = 0; w < width; w++)
		{
			launchRays(h, w, color);
			image[h * 3 * width + w * 3] = color.getRedUC();
			image[h * 3 * width + w * 3 + 1] = color.getGreenUC();
			image[h * 3 * width + w * 3 + 2] = color.getBlueUC();
		}
		std::cout << "\tLine " << h << "rendered" << std::endl;
	}

	std::cout << "Rendering over!" << std::endl;
}

void Raytracer::launchRays(int h, int w, Color &color)
{
	Ray ray = createRay(h, w);
	launchRay(ray, 1, color);
}

Ray Raytracer::createRay(int h, int w)
{
	Camera c = *scene->getCamera();
	Point3d pos;
	Vec3d dir;

	if (c.getProjectType() == CamProjectionType::PERSPECTIVE)
	{
		dir = Vec3d(w, h, c.getFocal());
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

	if (depth > 0)
	{
		if (calcIntersect(ray, intersect, normal, numShape))
		{
			color = calcAmbiantLight(scene->getShapes()[numShape], intersect);
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

	for (unsigned int numShape = 0; numShape < scene->getShapes().size(); ++numShape)
	{
		Shape *shape = scene->getShapes()[numShape];
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

	return (objColor * scene->getAmbiantColor());
}