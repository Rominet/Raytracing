#include "Scene.hpp"


Scene::Scene()
{
	this->ambiantColor.setRed(0.5);
	this->ambiantColor.setGreen(0.5);
	this->ambiantColor.setBlue(0.5);
}


Scene::~Scene()
{

}

void Scene::addShape(Shape *s)
{
	s->getTransform()->calcTransformations();
	shapes.push_back(s);
}

void Scene::addCamera(Camera c)
{
	//this->camera.setTransform(c.getTransform());
	this->camera.setFocal(c.getFocal());
	this->camera.setWidth(c.getWidth());
	this->camera.setHeight(c.getHeight());
	this->camera.setProjectionType(c.getProjectType());
}