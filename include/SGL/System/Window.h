#ifndef WINDOW_H
#define WINDOW_H
#include <functional>
#include <unordered_map>

#include "../Wrapper/Context.h"
#include "../Logger/Logger.h"
#include "Event.h"

//hashing for <int, int> pair
template<>
struct std::hash<std::pair<int,int>>
{
    size_t operator()(const std::pair<int,int>& pair) const noexcept
    {
        return std::hash<int>{}(pair.first) ^ std::hash<int>{}(pair.second);
    }
};

namespace sgl
{
    class Window
    {
        GLFWwindow* m_Window;

        inline static bool s_GLFW_ALREADY_INITIALIZED = false;

        GL::Context m_Context;

        inline static std::unordered_map<std::pair<int, int>, std::function<void()>> s_KeyCallbacks;

        inline static std::unordered_map<std::pair<int, int>, std::function<void()>> s_MouseCallbacks;

        inline static Event s_Event;

        inline static int s_Width;

        inline static int s_Height;

        bool opened;

        //callbacks
        static void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

        static void mouseCallback(GLFWwindow* window, int key, int action, int mods);

        static void closeCallback(GLFWwindow* window);

        static void resizeCallback(GLFWwindow* window, int width, int height);
    public:
        Window(Logger& logger, int contextMajorVersion, int contextMinorVersion, int width, int height, const char* name);

        Window(const Window& window) = delete;

        Window& operator=(const Window& window) = delete;

        constexpr const GL::Context& getContext() const {return m_Context;}

        constexpr const int getWidth() const {return s_Width;}

        constexpr const int getHeight() const {return s_Height;}

        bool isOpen() const;

        void close();

        void swapBuffers();

        void setKeyCallback(Keyboard::Key key, Keyboard::Action action, void(*func)());

        void setButtonCallback(Mouse::Button button, Mouse::Action action, void(*func)());

        const Event& pollEvents() const;

        ~Window();
    };
}



#endif //WINDOW_H
