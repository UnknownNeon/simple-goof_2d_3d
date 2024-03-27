#include "InputManager.h"
#include "iostream"
#include "thread"

int InputManager::up= 0;
int InputManager::right = 0;
int InputManager::forward = 0;

void InputManager::parallel_loop1()
{
	while (true) {
		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
			this->up = 1;
		else if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
			this->up = -1;
		else
		{
			this->up = 0;
		}
	}
}

void InputManager::parallel_loop2()
{
	while (true) {
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
			this->right = 1;
		else if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
			this->right = -1;

		else {
			this->right = 0;
		}
	}
}

InputManager::InputManager(GLFWwindow* window)
{
	this->window = window;
	fetch_inputs();
}
InputManager::~InputManager()
{
	stopThreads = true;
}
void InputManager::fetch_inputs()
{
	std::cout << "Entered the subroutine " << std::endl;
	stopThreads = false;
	std::thread thread1(&InputManager::parallel_loop1, this);
	std::cout << "started subroutine 1 " << std::endl;
	std::thread thread2(&InputManager::parallel_loop2, this);
	std::cout << "started subroutine 2 " << std::endl;

	thread1.detach();
	thread2.detach();

	//???not safe
}
