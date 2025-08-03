#ifndef BUFFERTYPE_H
#define BUFFERTYPE_H
#include "../../GL/glad.h"

namespace GL
{
    enum class BufferType : uint32_t
    {
        ARRAY = GL_ARRAY_BUFFER,
        ELEMENT_ARRAY = GL_ELEMENT_ARRAY_BUFFER,
        UNIFORM = GL_UNIFORM_BUFFER,
        INDIRECT_DRAW = GL_DRAW_INDIRECT_BUFFER
    };
}

#endif //BUFFERTYPE_H
