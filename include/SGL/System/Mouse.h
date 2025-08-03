#ifndef MOUSE_H
#define MOUSE_H
#include "GLFW/glfw3.h"

namespace sgl
{
    class Mouse
    {
        static void s_Callback(int button, int action, int mods);

    public:
        enum class Button
        {
            LEFT = GLFW_MOUSE_BUTTON_1,
            RIGHT = GLFW_MOUSE_BUTTON_2,
            MIDDLE = GLFW_MOUSE_BUTTON_3
        };

        enum class Action
        {
            RELEASE = GLFW_RELEASE,
            PRESS = GLFW_PRESS,
        };

        static bool isButtonPressed(Button button);

        inline static Button button;

        inline static Action action;

        friend class Window;
    };
} // sgl

#endif //MOUSE_H
