#include "Shader.h"

Shader::Shader(const char* shaderSource, GLenum shaderEnum)
	:shaderSource{ shaderSource }, shaderEnum{ shaderEnum }
{
    createShader();
}

void Shader::createShader()
{
    // build and compile our shader program
    // ------------------------------------

    shader = glCreateShader(shaderEnum);
    glShaderSource(shader, 1, &shaderSource, NULL);
    glCompileShader(shader);


    // check for shader compile errors
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::" << shaderEnum << "::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
}

unsigned int Shader::operator()()
{
	return shader;
}

