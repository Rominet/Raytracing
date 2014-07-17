#include <iostream>
#include "Scene.hpp"
#include "Sphere.hpp"
#include "Raytracer.hpp"

Scene  createFakeScene()
{
	Scene  s;

	Sphere *sph = new Sphere();
	sph->getTransform()->setPosition(Vec3d(-1.5, 3.0, -30.0));
	sph->setAmbiantCoeff(Vec3d(1.0, 0.0, 0.0));
	s.addShape(sph);

	Sphere *sph2 = new Sphere(2.0);
	sph2->getTransform()->setPosition(Vec3d(-2.26, -1.264, -30.0));
	sph2->setAmbiantCoeff(Vec3d(1.0, 1.0, 0.0));
	s.addShape(sph2);

	Sphere *sph3 = new Sphere();
	sph3->getTransform()->setPosition(Vec3d(-1.913, 1.80, -19.52));
	sph3->setAmbiantCoeff(Vec3d(0.0, 1.0, 0.5));
	s.addShape(sph3);

	Camera c;
	c.setWidth(640);
	c.setHeight(480);
	c.setProjectionType(CamProjectionType::ISOMETRIC);
	s.addCamera(c);

	return s;
}

int main(int argc, char** argv)
{
	Scene s = createFakeScene();


	
	Raytracer rt(s);

	rt.renderScene();
	rt.saveScene("rendu.ppm");


	return (0);
}