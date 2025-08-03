#include "Window.h"
#include <stdexcept>

namespace sgl
{
    void Window::keyboardCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
    {
        Keyboard::s_Callback(key, scancode, action, mods);
        s_Event.type = EventType::KEYBOARD;

        if (auto func = s_KeyCallbacks[{key, action}])
            func();
    }

    void Window::mouseCallback(GLFWwindow *window, int key, int action, int mods)
    {
        s_Event.type = EventType::MOUSE;

        Mouse::s_Callback(key, action, mods);

        if (auto func = s_MouseCallbacks[{key, action}])
            func();
    }

    void Window::closeCallback(GLFWwindow *window)
    {
        s_Event.type = EventType::WINDOW;
        s_Event.windowState = WindowState::CLOSED;
    }

    void Window::resizeCallback(GLFWwindow *window, int width, int height)
    {
        s_Event.type = EventType::WINDOW;
        s_Event.windowState = WindowState::RESIZED;

        s_Width = width;

        s_Height = height;
    }

    Window::Window(Logger &logger, int contextMajorVersion, int contextMinorVersion, int width, int height,
                   const char *name)
        : m_Context(contextMajorVersion, contextMinorVersion),opened(false)
    {
        if (!s_GLFW_ALREADY_INITIALIZED)
        {
            if (!glfwInit())
                logger.log("GLFW initialization failed");

            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, contextMajorVersion);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, contextMinorVersion);

            m_Window = glfwCreateWindow(width, height, name, nullptr, nullptr);

            if (!m_Window)
                logger.log("Window creation failed");

            glfwMakeContextCurrent(m_Window);

            glfwSetKeyCallback(m_Window, keyboardCallback);

            glfwSetMouseButtonCallback(m_Window, mouseCallback);

            glfwSetWindowCloseCallback(m_Window, closeCallback);

            glfwSetFramebufferSizeCallback(m_Window, resizeCallback);

            opened = true;
        }

        if (m_Context.loadOpenGLFunctions())
            logger.log("Failed to load OpenGL functions");

        s_GLFW_ALREADY_INITIALIZED = true;

        s_Width = width;

        s_Height = height;
    }

    bool Window::isOpen() const
    {
        return opened;
    }

    void Window::close()
    {
        glfwDestroyWindow(m_Window);

        m_Window = nullptr;

        opened = false;
    }

    void Window::swapBuffers()
    {
        glfwSwapBuffers(m_Window);
    }

    void Window::setKeyCallback(Keyboard::Key key, Keyboard::Action action, void(*func)())
    {
        s_KeyCallbacks[{static_cast<int>(key), static_cast<int>(action)}] = func;
    }

    void Window::setButtonCallback(Mouse::Button button, Mouse::Action action, void(*func)())
    {
        s_MouseCallbacks[{static_cast<int>(button), static_cast<int>(action)}] = func;
    }

    const Event& Window::pollEvents() const
    {
        s_Event.type = EventType::NONE;

        s_Event.windowState = WindowState::NONE;

        glfwPollEvents();

        return s_Event;
    }

    Window::~Window()
    {
        if (m_Window)
            glfwDestroyWindow(m_Window);

        glfwTerminate();
    }
}
