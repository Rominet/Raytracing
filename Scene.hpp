#pragma once
#include "Camera.hpp"
#include "Shape.hpp"
#include "Model.hpp"
#include <vector>


class Scene
{
private:
	Model _model;
	Camera camera;
	std::vector<Shape*> shapes;
	Color ambiantColor;

public:
	Scene();
	~Scene();

	inline Model getModel() const
	{
		return this->_model;
	}
	inline Camera getCamera() const { return this->camera; }
	inline std::vector<Shape*> getShapes() const { return this->shapes; }
	inline Color getAmbiantColor() const { return this->ambiantColor; }

	inline void setModel(Model model)
	{
		this->_model = model;
	};

	void addCamera(Camera c);
	void addShape(Shape *s);
};

