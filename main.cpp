#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Logger.h"

//TODO - CHANGE TO DYNAMICALLY READ FROM CONFIG FILE
#define SCREEN_X 800
#define SCREEN_Y 800

int main()
{
	Logger::LogInformation("Starting OpenGL Engine");

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(SCREEN_X, SCREEN_Y, "OpenGLEngine", NULL, NULL);
	if (window == NULL)
	{
		Logger::LogError("Could not create Window");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	gladLoadGL();

	glViewport(0, 0, SCREEN_X, SCREEN_Y);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}