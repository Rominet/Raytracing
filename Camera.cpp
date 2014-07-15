#include "Camera.hpp"


Camera::Camera()
{
	width = 1024;
	height = 768;

	focal = 1.0;
	projectionType = CamProjectionType::PERSPECTIVE;
}


Camera::~Camera()
{
}

