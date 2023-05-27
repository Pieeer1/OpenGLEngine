#include <iostream>
#include <glad/glad.h> // do not remove, causes compilation error
#include <GLFW/glfw3.h>
#include "Logger.h"
#include "FileExtensions.h"
#include "Shader.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "ElementArrayBuffer.h"

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

	
	GLfloat vertices[] =
	{
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f, // Upper corner
		-0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner left
		0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f, // Inner right
		0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f // Inner down
	};

	GLuint indices[] =
	{
		0, 3, 5,
		3, 2, 4,
		5, 4, 1
	};

	//Shader Setup
	Shader defaultShader("default.vert", "default.frag");
	VertexArray vertexArray;
	vertexArray.Bind();

	VertexBuffer vertexBuffer(vertices, sizeof(vertices));
	ElementArrayBuffer elementArrayBuffer(indices, sizeof(indices));

	vertexArray.LinkVertexBuffer(vertexBuffer, 0);
	vertexArray.Unbind();
	vertexBuffer.Unbind();
	elementArrayBuffer.Unbind();


	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		defaultShader.Activate();

		vertexArray.Bind();

		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	defaultShader.Delete();
	vertexArray.Delete();
	vertexBuffer.Delete();
	elementArrayBuffer.Delete();

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}