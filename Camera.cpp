#include "Camera.hpp"


Camera::Camera()
{
	width = 1024;
	height = 768;

	fov = 40.0;
	projectionType = CamProjectionType::PERSPECTIVE;
}


Camera::~Camera()
{
}

