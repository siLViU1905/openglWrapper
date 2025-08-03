#include "Keyboard.h"

namespace sgl
{
    void Keyboard::s_Callback(int key, int scancode, int action, int mods)
    {
        Keyboard::key = static_cast<Key>(key);
        Keyboard::action = static_cast<Action>(action);
        Keyboard::mod = static_cast<Modifier>(mods);
    }

    bool Keyboard::isKeyPressed(Key key)
    {
        return glfwGetKey(glfwGetCurrentContext(), static_cast<int>(key)) == GLFW_PRESS;
    }
}
