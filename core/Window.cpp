#include "Window.h"

void _Window::framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void _Window::processInput()
{
	if (glfwGetKey(GL_WINDOW, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(GL_WINDOW, true);
	if (glfwGetKey(GL_WINDOW, GLFW_KEY_F1) == GLFW_PRESS)
	{
		if (toggle == false) {
		gf_render::setWireframeMode(!toggle);
		toggle = true;
		}
		else {
			gf_render::setWireframeMode(!toggle);
			toggle = false;
		}
	}
	
}

void _Window::swap_and_pollevents()
{
	glfwPollEvents();
	glfwSwapBuffers(GL_WINDOW);

}

_Window::_Window() : GL_WINDOW(nullptr){
	
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GL_WINDOW = glfwCreateWindow(W_WIDTH, W_HEIGHT, "_Window", NULL, NULL);
	if (GL_WINDOW == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}
	
	glfwMakeContextCurrent(GL_WINDOW);

	//Initializing glad 
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;

	}

	glfwSetFramebufferSizeCallback(GL_WINDOW, framebuffer_size_callback);

}


_Window::~_Window()
{
	glfwTerminate();
	std::cout << "[GLFW :] Terminated" << std::endl;
}

bool _Window::isWindowOpen()
{
	return !glfwWindowShouldClose(GL_WINDOW);
}


void  _Window::processInput(goof::Camera& camera,GLFWwindow* window )
{
	window = GL_WINDOW;

	if (glfwGetKey(GL_WINDOW, GLFW_KEY_F1) == GLFW_PRESS)
	{
		if (toggle == false) {
			gf_render::setWireframeMode(!toggle);
			toggle = true;
		}
		else {
			gf_render::setWireframeMode(!toggle);
			toggle = false;
		}
	}
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	float cameraSpeed = 0.1f;
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera.cameraPos += cameraSpeed * camera.cameraFront;
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera.cameraPos -= cameraSpeed * camera.cameraFront;
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera.cameraPos -= glm::normalize(glm::cross(camera.cameraFront, camera.cameraUp)) * cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera.cameraPos += glm::normalize(glm::cross(camera.cameraFront, camera.cameraUp)) * cameraSpeed;
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
		camera.cameraPos += cameraSpeed * camera.cameraUp;
	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
		camera.cameraPos -= cameraSpeed * camera.cameraUp;
}
