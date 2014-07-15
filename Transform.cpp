#include "Transform.hpp"
#include "Matrix.hpp"

Transform::Transform()
{
	this->position = new Vec3d(0.0, 0.0, 0.0);
	this->rotation = new Vec3d(0.0, 0.0, 0.0);
	this->scale = new Vec3d(1.0, 1.0, 1.0);

	transformation = new Matrix<double, 4, 4>();
	transformation->initIdentity();
	transformationInv = new Matrix<double, 4, 4>();
	transformationInv->initIdentity();
}

Transform::Transform(Vec3d position, Vec3d rotation, Vec3d scale)
{
	this->position = new Vec3d(position);
	this->rotation = new Vec3d(rotation);
	this->scale = new Vec3d(scale);

	transformation = new Matrix<double, 4, 4>();
	transformation->initIdentity();
	transformationInv = new Matrix<double, 4, 4>();
	transformationInv->initIdentity();
}

Transform::~Transform()
{
	delete position;
	delete rotation;
	delete scale;

	delete transformation;
	delete transformationInv;

	std::cout << "delete Transform" << std::endl;
}

void Transform::calcTransformations()
{
	calcTranslations();
	calcRotations();
	calcScaling();
}

void Transform::calcTranslations()
{
	Vec3d pos = *position;

	Matrix<double, 4, 4> translateMat = createTranslateMatrix(pos[0], pos[1], pos[2]);
	Matrix<double, 4, 4> translateMatInv = createTranslateMatrix(-pos[0], -pos[1], -pos[2]);

	*transformation = translateMat * *transformation;
	*transformationInv = translateMatInv * *transformation;
}

void Transform::calcRotations()
{
	Vec3d rot = *rotation;

	Matrix<double, 4, 4> rotateMat = createXRotateMatrix(rot[0]) * createYRotateMatrix(rot[1]) * createZRotateMatrix(rot[2]);
	Matrix<double, 4, 4> rotateMatInv = createXRotateMatrix(-rot[0]) * createYRotateMatrix(-rot[1]) * createZRotateMatrix(-rot[2]);

	*transformation = rotateMat * *transformation;
	*transformationInv = rotateMatInv * *transformation;

}

void Transform::calcScaling()
{
	Vec3d sc = *scale;

	Matrix<double, 4, 4> scaleMat = createScaleMatrix(sc[0], sc[1], sc[2]);
	Matrix<double, 4, 4> scaleMatInv = createScaleMatrix(-sc[0], -sc[1], -sc[2]);

	*transformation = scaleMat * *transformation;
	*transformationInv = scaleMatInv * *transformation;
}

