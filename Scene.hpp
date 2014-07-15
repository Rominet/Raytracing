#pragma once
#include "Camera.hpp"
#include "Shape.hpp"
#include <vector>

class Scene
{
private:
	Camera camera;
	std::vector<Shape*> shapes;
	Color ambiantColor;

public:
	Scene();
	~Scene();

	Camera getCamera() const { return this->camera; }
	std::vector<Shape*> getShapes() const { return this->shapes; }
	Color getAmbiantColor() const { return this->ambiantColor; }
};

