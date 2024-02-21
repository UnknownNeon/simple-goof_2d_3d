#pragma once

#include "Window.h"
#include "Shader.h"
#include "Camera.h"
#include "Entity.h"



namespace goof {

	static glm::mat4 prespective = glm::perspective(glm::radians(45.0f), (float)W_WIDTH / (float)W_HEIGHT, 0.1f, 1000.0f);
	static glm::mat4 orthographic = glm::ortho(0.f, (float)W_HEIGHT,(float) W_WIDTH, 0.f, -1.f , 10.f);

	void run();
	void setViewMode(Shader& shader, glm::mat4 MODE);

	namespace IMGUI {
		void Init(GLFWwindow* The_Window);
		void Destroy();
		void render_primitives(gf_render::shapes& shape,Shader& sha, goof::Texture2D* tex=nullptr);
	}
}