#pragma once

#include "Matrix.hpp"
#include "Ray.hpp"
#include "Vec3d.hpp"
#include "Point3d.hpp"
#include "Transform.hpp"
#include "Color.hpp"

class Shape
{
private:
	Vec3d ambiant_coeff;
	Vec3d diffuse_coeff;
	Vec3d specular_coeff;
	Transform *transform;
	float alpha;

public:
	Shape();
	~Shape();
	
	inline Vec3d getAmbiantCoeff() const { return this->ambiant_coeff; }
	inline void setAmbiantCoeff(Vec3d ambientCoeff) { this->ambiant_coeff = ambientCoeff; }
	Vec3d getDifuseCoeff() const { return this->diffuse_coeff; }
	inline void setDifuseCoeff(Vec3d difuseCoeff)
	{
		this->diffuse_coeff = difuseCoeff;
	}
	Vec3d getSpecularCoeff() const { return this->specular_coeff; }
	inline void setSpecularCoeff(Vec3d specularCoeff)
	{
		this->specular_coeff = specularCoeff;
	}
	Transform *getTransform() const { return this->transform; }
	void setTransform(Vec3d position, Vec3d rotation, Vec3d scale);

	virtual bool isRayIntersecting(const Ray ray, Point3d &intersectPoint, Vec3d &intersectNormal) const = 0;

	Color getAmbiantColor(Point3d intersect) const;

	inline float getAlpha() const
	{
		return alpha;
	}

	inline void setAlpha(float alpha)
	{
		this->alpha = alpha;
	}
};

