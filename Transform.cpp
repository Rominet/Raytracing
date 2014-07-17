#include "Transform.hpp"
#include "Matrix.hpp"

Transform::Transform()
{
	this->position = Vec3d(0.0, 0.0, 0.0);
	this->rotation = Vec3d(0.0, 0.0, 0.0);
	this->scale = Vec3d(1.0, 1.0, 1.0);

	transformation = Matrix<double, 4, 4>();
	transformation.initIdentity();
	transformationInv = Matrix<double, 4, 4>();
	transformationInv.initIdentity();
}

Transform::Transform(Vec3d position, Vec3d rotation, Vec3d scale)
{
	this->position = Vec3d(position);
	this->rotation = Vec3d(rotation);
	this->scale = Vec3d(scale);

	transformation = Matrix<double, 4, 4>();
	transformation.initIdentity();
	transformationInv = Matrix<double, 4, 4>();
	transformationInv.initIdentity();
}

Transform::~Transform()
{
}

void Transform::calcTransformations()
{
	calcTranslations();
	calcRotations();
	calcScaling();

	std::cout << "Transform Mat" << transformation << std::endl;
	std::cout << "Transform Mat Inv" << transformationInv << std::endl;
}

void Transform::calcTranslations()
{
	Matrix<double, 4, 4> translateMat = createTranslateMatrix(position[0], position[1], position[2]);
	Matrix<double, 4, 4> translateMatInv = createTranslateMatrix(-position[0], -position[1], -position[2]);

	transformation = translateMat * transformation;
	transformationInv = translateMatInv * transformationInv;
}

void Transform::calcRotations()
{
	Matrix<double, 4, 4> rotateMat = createXRotateMatrix(rotation[0]) * createYRotateMatrix(rotation[1]) * createZRotateMatrix(rotation[2]);
	Matrix<double, 4, 4> rotateMatInv = createXRotateMatrix(-rotation[0]) * createYRotateMatrix(-rotation[1]) * createZRotateMatrix(-rotation[2]);

	transformation = rotateMat * transformation;
	transformationInv = rotateMatInv * transformationInv;

}

void Transform::calcScaling()
{
	Matrix<double, 4, 4> scaleMat = createScaleMatrix(scale[0], scale[1], scale[2]);
	Matrix<double, 4, 4> scaleMatInv = createScaleMatrix(1.0 / scale[0], 1.0 / scale[1], 1.0 / scale[2]);

	transformation = scaleMat * transformation;
	transformationInv = scaleMatInv * transformationInv;
}

