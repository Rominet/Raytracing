#include "Transform.h"
#include "Matrix.hpp"

Transform::Transform()
{
	this->position = Vec3d(0, 0, 0);
	this->rotation = Vec3d(0, 0, 0);
	this->scale = Vec3d(1, 1, 1);

	transformation.initIdentity();
	transformationInv.initIdentity();
}

Transform::Transform(Vec3d position, Vec3d rotation, Vec3d scale)
{
	this->position = Vec3d(position);
	this->rotation = Vec3d(rotation);
	this->scale = Vec3d(scale);

	transformation.initIdentity();
	transformationInv.initIdentity();
}

Transform::~Transform()
{
}

void Transform::calcTranslations()
{
	translateMat = createTranslateMatrix(position[0], position[1], position[2]);
	translateMatInv = createTranslateMatrix(-position[0], -position[1], -position[2]);

	transformation *= translateMat;
	transformationInv *= translateMatInv;
}

void Transform::calcRotations()
{
	rotateMat = createXRotateMatrix(rotation[0]) * createYRotateMatrix(rotation[1]) * createZRotateMatrix(rotation[2]);
	rotateMatInv = createXRotateMatrix(-rotation[0]) * createYRotateMatrix(-rotation[1]) * createZRotateMatrix(-rotation[2]);

	transformation *= rotateMat;
	transformationInv *= rotateMatInv;

}

void Transform::calcScaling()
{
	scaleMat = createScaleMatrix(scale[0], scale[1], scale[2]);
	scaleMatInv = createScaleMatrix(-scale[0], -scale[1], -scale[2]);

	transformation *= scaleMat;
	transformationInv *= scaleMatInv;
}

