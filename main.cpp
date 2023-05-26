#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Logger.h"
#include "FileExtensions.h"

//TODO - CHANGE TO DYNAMICALLY READ FROM CONFIG FILE
#define SCREEN_X 800
#define SCREEN_Y 800

GLuint SetupVertexShaders();
GLuint SetupFragmentShaders();

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

	//SHADERS
	GLuint vertexShader = SetupVertexShaders();
	GLuint fragmentShader = SetupFragmentShaders();

	GLuint shaderProgram = glCreateProgram();

	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);

	glLinkProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

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


	//BUFFER BINDING
	GLuint VAO, VBO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);


	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram);
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteProgram(shaderProgram);

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}

GLuint SetupVertexShaders()
{
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	std::string referenceableVertexString = FileExtensions::ReadEntireFileText("vertices.vert");
	const char* verticesString = referenceableVertexString.c_str();
	glShaderSource(vertexShader, 1, &verticesString, NULL);
	glCompileShader(vertexShader);
	return vertexShader;
}
GLuint SetupFragmentShaders()
{
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	std::string referenceableFragmentString = FileExtensions::ReadEntireFileText("fragments.frag");
	const char* fragmentString = referenceableFragmentString.c_str();
	glShaderSource(fragmentShader, 1, &fragmentString, NULL);
	glCompileShader(fragmentShader);
	return fragmentShader;
}
