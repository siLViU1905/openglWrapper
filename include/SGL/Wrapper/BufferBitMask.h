#ifndef BUFFERBITMASK_H
#define BUFFERBITMASK_H
#include <cstdint>

#include "../../GL/glad.h"

namespace GL
{
    enum class BufferBitMask : uint32_t
    {
        COLOR = GL_COLOR_BUFFER_BIT,
        DEPTH = GL_DEPTH_BUFFER_BIT,
        STENCIL = GL_STENCIL_BUFFER_BIT,

        COLOR_DEPTH = GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT,

        COLOR_DEPTH_STENCIL = GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT
    };
}



#endif //BUFFERBITMASK_H
