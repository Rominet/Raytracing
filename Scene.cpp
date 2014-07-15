#include "Scene.hpp"


Scene::Scene()
{
	this->camera = new Camera();
}


Scene::~Scene()
{
	delete camera;
}

void Scene::addShape(Shape *s)
{
	s->getTransform()->calcTransformations();
	shapes.push_back(s);
}

void Scene::addCamera(Camera c)
{

	this->camera->setFocal(c.getFocal());
	this->camera->setWidth(c.getWidth());
	this->camera->setHeight(c.getHeight());
	this->camera->setProjectionType(c.getProjectType());
}