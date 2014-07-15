#pragma once
#include "Point3d.hpp"
#include "Vec3d.hpp"
#include "Ray.hpp"
#include "Transform.hpp"

enum CamProjectionType { PERSPECTIVE, ISOMETRIC };

class Camera
{
protected:
	double focal;
	CamProjectionType projectionType;
	int width;
	int height;

	Transform *transform;

public:
	Camera();
	virtual ~Camera();

	void setFocal(double focal) { this->focal = focal; }
	double getFocal() const { return this->focal; }

	void setProjectionType(CamProjectionType projectionType) { this->projectionType = projectionType;  }
	CamProjectionType getProjectType() const { return this->projectionType; }
	
	void setWidth(int width) { this->width = width;	}
	int getWidth() const { return this->width; }
	
	void setHeight(int height) { this->height = height; }
	int getHeight() const { return this->height; }
};

