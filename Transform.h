#pragma once
#include "Vec3d.hpp"

class Transform
{
private:
	Vec3d position;
	Vec3d scale;
	Vec3d rotation;

	Matrix<double, 4, 4> translateMat;
	Matrix<double, 4, 4> rotateMat;
	Matrix<double, 4, 4> scaleMat;
	Matrix<double, 4, 4> translateMatInv;
	Matrix<double, 4, 4> rotateMatInv;
	Matrix<double, 4, 4> scaleMatInv;
	Matrix<double, 4, 4> transformation;
	Matrix<double, 4, 4> transformationInv;

public:
	Transform();
	Transform(Vec3d position, Vec3d rotation, Vec3d scale);
	~Transform();

	void calcTranslations();
	void calcRotations();
	void calcScaling();
	Matrix<double, 4, 4> getTransformation() const { return this->transformation; }
	Matrix<double, 4, 4> getTransformationInv() const { return this->transformationInv; }

	Vec3d getPosition() const { return this->position; }
	Vec3d getRotation() const { return this->rotation; }
	Vec3d getScale() const { return this->scale; }
};

