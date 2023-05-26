#include "Shader.h"

Shader::Shader(const char* vertexFilePath, const char* fragmentFilePath)
{
	GLuint vertexShader = SetupShader(vertexFilePath, GL_VERTEX_SHADER);
	GLuint fragmentShader = SetupShader(fragmentFilePath, GL_FRAGMENT_SHADER);

	ID = glCreateProgram();

	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);

	glLinkProgram(ID);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::Activate()
{
	glUseProgram(ID);
}
void Shader::Delete()
{
	glDeleteProgram(ID);
}