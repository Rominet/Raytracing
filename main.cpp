#include <iostream>
#include "Scene.hpp"
#include "Sphere.hpp"
#include "Raytracer.hpp"

//Scene * createFakeScene()
//{
//	Scene * s = new Scene();
//
//	Sphere *sph = new Sphere();
//	sph->getTransform()->setPosition(Vec3d(-5.0, 6.0, -3.0));
//
//	Camera c;
//	c.setWidth(640);
//	c.setHeight(480);
//
//
//	s->addShape(sph);
//	s->addCamera(c);
//
//	return s;
//}

Scene  createFakeScene()
{
	Scene  s;

	Sphere *sph = new Sphere();
	sph->getTransform().setPosition(Vec3d(-5.0, 6.0, -3.0));
	sph->setAmbiantCoeff(Vec3d(1.0, 0.0, 0.0));

	Camera c;
	c.setWidth(120);
	c.setHeight(120);


	s.addShape(sph);
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