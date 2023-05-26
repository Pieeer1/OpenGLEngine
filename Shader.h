#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "FileExtensions.h"

class Shader
{
public:
	GLuint ID;
	Shader(const char* vertexFilePath, const char* fragmentFilePath);

	void Activate();
	void Delete();

private:
	GLuint SetupShader(const char* filePath, int shaderType)
	{
		GLuint shader = glCreateShader(shaderType);
		std::string referenceableString = FileExtensions::ReadEntireFileText(filePath);
		const char* c_str = referenceableString.c_str();
		glShaderSource(shader, 1, &c_str, NULL);
		glCompileShader(shader);
		return shader;
	}
};