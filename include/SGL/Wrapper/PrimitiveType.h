#ifndef PRIMITIVETYPE_H
#define PRIMITIVETYPE_H
#include <cstdint>

#include "../../GL/glad.h"

namespace GL
{
    enum class PrimitiveType : uint32_t
    {
        POINT = GL_POINT,
        POINTS = GL_POINTS,
        LINE = GL_LINE,
        LINES = GL_LINES,
        TRIANGLES = GL_TRIANGLES,
        TRIANGLE_STRIP = GL_TRIANGLE_STRIP,
        TRIANGLE_FAN = GL_TRIANGLE_FAN,
        QUADS = GL_QUADS,
        QUAD_STRIP = GL_QUAD_STRIP,
        POLYGON = GL_POLYGON
    };
}

#endif //PRIMITIVETYPE_H
