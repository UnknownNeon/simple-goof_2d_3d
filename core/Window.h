#pragma once
#include "Renderer.h"
#include "GLFW/glfw3.h"


#define W_HEIGHT 400
#define W_WIDTH 800

#include <iostream>
#include "Camera.h"

class _Window {

		GLFWwindow* GL_WINDOW;

		//Rule of 5:
		_Window(const _Window& other) = delete;
		_Window(_Window&& other) = delete;
		_Window& operator=(_Window&& other) = delete;
		_Window& operator=(const _Window& other) = delete;

	private:
		bool toggle = false;
		//Callbacks
		static void framebuffer_size_callback(GLFWwindow* window, int width, int height);


	public:
		_Window();
		~_Window();

		inline GLFWwindow* getWindow() { return GL_WINDOW; }

		void processInput(goof::Camera& camera,GLFWwindow* window = nullptr);
		void processInput();
		void swap_and_pollevents();
		bool isWindowOpen();
};



