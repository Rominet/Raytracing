#include <iostream>
#include "Scene.hpp"
#include "Sphere.hpp"
#include "Raytracer.hpp"
#include "DescriptionFileParser.hpp"

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

//int main(int argc, char** argv)
//{
//	Scene s = createFakeScene();
//
//
//	
//	Raytracer rt(s);
//
//	rt.renderScene();
//	rt.saveScene("rendu.ppm");
//
//
//	return (0);
//}

int main(int argc, char** argv)
{
	DescriptionFileParser parser("scene.rtscn");

	parser.parseFile();

	Scene scn = parser.getScene();
	std::cout << scn.getModel().getAmbiant() << std::endl;
	std::cout << scn.getModel().getThreshold() << std::endl;
	std::cout << scn.getModel().getDepth() << std::endl;
	std::cout << std::endl;
	std::cout << scn.getCamera().getFocal() << std::endl;
	std::cout << scn.getCamera().getHeight() << std::endl;
	std::cout << scn.getCamera().getWidth() << std::endl;
	std::cout << scn.getCamera().getProjectType() << std::endl;
	return (0);
}