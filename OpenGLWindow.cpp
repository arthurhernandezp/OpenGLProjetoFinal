#include "OpenGLWindow.h"

OpenGLWindow::OpenGLWindow(unsigned int width, unsigned int height, const char* windowTitle, GLFWmonitor* fullscreen, GLFWwindow* share)
    : WIDTH{ width }, HEIGHT{ height }, windowTitle{ windowTitle }, fullscreen{fullscreen}, share{share}
{}

OpenGLWindow::~OpenGLWindow()
{

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    glfwDestroyWindow(window);

}

bool OpenGLWindow::initialize()
{
    if (!initializeGLFW() || !createWindow())
    {
        return false;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, windowResize);

    return true;
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void OpenGLWindow::windowResize(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

bool OpenGLWindow::shouldClose() const
{
    return glfwWindowShouldClose(window);

}
// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void OpenGLWindow::processEvents()
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void OpenGLWindow::pollEvents() const
{
    glfwPollEvents();
}

// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
// -------------------------------------------------------------------------------
void OpenGLWindow::swapBuffers() const
{
    glfwSwapBuffers(window);
}

bool OpenGLWindow::initializeGLFW()
{
    // glfw: initialize and configure
// ------------------------------
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    return true;
}

bool OpenGLWindow::createWindow()
{
    // glfw window creation
    // --------------------
    window = glfwCreateWindow(WIDTH, HEIGHT, windowTitle, nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return false;
    }
    return true;
}

