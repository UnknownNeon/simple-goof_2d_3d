#pragma once
#include "Shader.h"
#include "Camera.h"
#include "Window.h"



namespace goof {

	static float i = 2.f;
	static glm::mat4 prespective = glm::perspective(glm::radians(45.0f), (float)W_WIDTH / (float)W_HEIGHT, 0.1f, 100.0f);
	static glm::mat4 orthographic = glm::ortho(-2.f * i, 2.f * i, -1.5f * i, 1.5f * i , -1.f , 1.f);
	void run();
	void setViewMode(Shader& shader, glm::mat4 MODE);
	namespace IMGUI {
		void Init(GLFWwindow* The_Window);
		void Destroy();
	}
}