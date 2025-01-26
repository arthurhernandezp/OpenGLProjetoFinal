#pragma once
#include <GLFW/glfw3.h>
#include <iostream>
class OpenGLWindow
{
public:
	OpenGLWindow() = default;
	OpenGLWindow(unsigned int width, unsigned int height, const char *windowTitle, GLFWmonitor *fullscreen = nullptr, GLFWwindow *share = nullptr);
	~OpenGLWindow();

	bool initialize();
	bool shouldClose() const;
	void processEvents();
	void pollEvents() const;
	void swapBuffers() const;

private:

	bool initializeGLFW();
	bool createWindow();

	GLFWwindow* window{ nullptr };

	const unsigned int WIDTH = 800;
	const unsigned int HEIGHT = 600;

	const char* windowTitle{ "Janela OpenGL" };
	GLFWmonitor* fullscreen{ nullptr };
	GLFWwindow* share{nullptr};
	static void windowResize(GLFWwindow* window, int width, int height);

};

