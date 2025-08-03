
#ifndef CONTEXT_H
#define CONTEXT_H
#include "BufferBitMask.h"
#include "../../GL/glad.h"
#include "../System/GLFW/glfw3.h"
#include "Capability.h"
#include "PrimitiveType.h"
#include "DataType.h"

namespace sgl
{
    class Window;
}

namespace GL
{
    class Context
    {
        int m_VersionMinor;

        int m_VersionMajor;

         bool loadOpenGLFunctions();
    public:
        constexpr Context(int versionMajor, int versionMinor): m_VersionMajor(versionMajor),
                                                               m_VersionMinor(versionMinor)
        {
        }

        Context(const Context& context) = delete;

        Context& operator=(const Context& context) = delete;

        void setClearColor(float r, float g, float b, float a) const;

        void setViewport(int xpos, int ypos, int width, int height) const;

        void enable(Capability capability) const;

        void disable(Capability capability) const;

        void clear(BufferBitMask mask) const;

        void drawArrays(PrimitiveType mode, int first, int count) const;

        void drawElements(PrimitiveType mode, int count, DataType type, const void* indices) const;

        friend class sgl::Window;
    };
} // GL

#endif //CONTEXT_H
