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

	inline void setFocal(double focal) { this->focal = focal; }
	inline double getFocal() const { return this->focal; }

	inline void setProjectionType(CamProjectionType projectionType) { this->projectionType = projectionType;  }
	inline CamProjectionType getProjectType() const { return this->projectionType; }
	
	inline void setWidth(int width) { this->width = width;	}
	inline int getWidth() const { return this->width; }
	
	inline void setHeight(int height) { this->height = height; }
	inline int getHeight() const { return this->height; }
};

