#include "Mouse.h"

namespace sgl {
    void Mouse::s_Callback(int button, int action, int mods)
    {
        Mouse::button = static_cast<Button>(button);
        Mouse::action = static_cast<Action>(action);
    }

    bool Mouse::isButtonPressed(Button button)
    {
        return glfwGetMouseButton(glfwGetCurrentContext(), static_cast<int>(button)) == GLFW_PRESS;
    }
} // sgl