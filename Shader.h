#pragma once
#include <iostream>
#include <glad/glad.h>

class Shader
{
public:
	Shader(const char* shaderSource, GLenum shaderEnum);
	void createShader();
	unsigned int operator()();

private:
	GLenum shaderEnum{};
	const char* shaderSource = nullptr;
	unsigned int shader;
	int success{};
	char infoLog[512]{};
};

