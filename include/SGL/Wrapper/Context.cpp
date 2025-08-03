#include "Context.h"

namespace GL
{
    bool Context::loadOpenGLFunctions()
    {
        return !gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));
    }

    void Context::setClearColor(float r, float g, float b, float a) const
    {
        glClearColor(r, g, b, a);
    }

    void Context::setViewport(int xpos, int ypos, int width, int height) const
    {
        glViewport(xpos, ypos, width, height);
    }

    void Context::enable(Capability capability) const
    {
        glEnable(static_cast<uint32_t>(capability));
    }

    void Context::disable(Capability capability) const
    {
        glDisable(static_cast<uint32_t>(capability));
    }

    void Context::clear(BufferBitMask mask) const
    {
        glClear(static_cast<uint32_t>(mask));
    }

    void Context::drawArrays(PrimitiveType mode, int first, int count) const
    {
        glDrawArrays(static_cast<uint32_t>(mode), first, count);
    }

    void Context::drawElements(PrimitiveType mode, int count, DataType type, const void *indices) const
    {
        glDrawElements(static_cast<uint32_t>(mode), count, static_cast<uint32_t>(type), indices);
    }
} // GL
