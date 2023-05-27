#pragma once
#include <glad/glad.h>
class ElementArrayBuffer
{
public:
	GLuint ID;
	ElementArrayBuffer(GLuint* indices, GLsizeiptr size);

	void Bind();
	void Unbind();
	void Delete();
};

