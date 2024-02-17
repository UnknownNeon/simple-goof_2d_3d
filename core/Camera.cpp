#include "Camera.h"

goof::Camera::Camera()
{
	
}

goof::Camera::~Camera() {

}

glm::mat4 goof::Camera::lookAt()
{
	glm::mat4 view;
	view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	return view;
}
glm::mat4 goof::Camera::follow_lookAt()
{
	glm::mat4 view;
	view = glm::lookAt(camera_Pos, camera_Pos + cameraFront, cameraUp);
	return view;
}

void goof::Camera::reset_camera()
{
	cameraPos = glm::vec3(0.0f, 0.0f, 0.0f);
	cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
}
