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

	inline Camera getCamera() const { return this->camera; }
	inline std::vector<Shape*> getShapes() const { return this->shapes; }
	inline Color getAmbiantColor() const { return this->ambiantColor; }

	void addCamera(Camera c);
	void addShape(Shape *s);
};

