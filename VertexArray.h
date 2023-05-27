#pragma once
#include "VertexBuffer.h"
class VertexArray
{
public:
	GLuint ID;
	VertexArray();

	void LinkVertexBuffer(VertexBuffer vertexBuffer, GLuint layout);

	void Bind();
	void Unbind();
	void Delete();
};

