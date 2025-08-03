#ifndef BUFFERUSAGE_H
#define BUFFERUSAGE_H
#include "../../GL/glad.h"

namespace GL
{
    enum class BufferUsage : uint32_t
    {
        STATIC = GL_STATIC_DRAW,
        DYNAMIC = GL_DYNAMIC_DRAW
    };
}

#endif //BUFFERUSAGE_H
