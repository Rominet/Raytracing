#pragma once
#include "Vec3d.hpp"

class Transform
{
private:
	Vec3d position;
	Vec3d scale;
	Vec3d rotation;

	Matrix<double, 4, 4> transformation;
	Matrix<double, 4, 4> transformationInv;

public:
	Transform();
	Transform(Vec3d position, Vec3d rotation, Vec3d scale);
	~Transform();

	void calcTranslations();
	void calcRotations();
	void calcScaling();
	void calcTransformations();

	Matrix<double, 4, 4> getTransformation() const { return this->transformation; }
	Matrix<double, 4, 4> getTransformationInv() const { return this->transformationInv; }

	Vec3d getPosition() const { return this->position; }
	void setPosition(Vec3d position) { 	this->position.setValues(position); }
	Vec3d getRotation() const { return this->rotation; }
	void setRotation(Vec3d rotation) { this->rotation.setValues(rotation); }
	Vec3d getScale() const { return this->scale; }
	void setScale(Vec3d scale) { this->scale.setValues(scale); }
};

