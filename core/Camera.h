#pragma once
#include "Util.h"

namespace goof {

	class Camera {
		public:
			glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 1.0f);
			glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
			glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	public:
		Camera();
		~Camera();
		glm::mat4 lookAt();

		void reset_camera();

	};
}