#ifndef WRAPMODE_H
#define WRAPMODE_H
#include <cstdint>
#include "../../GL/glad.h"

namespace GL
{
    enum class WrapMode
    {
        REPEAT = GL_REPEAT,
        MIRRORED_REPEAT = GL_MIRRORED_REPEAT,
        CLAMP_TO_EDGE = GL_CLAMP_TO_EDGE,
        CLAMP_TO_BORDER = GL_CLAMP_TO_BORDER
    };
} // GL

#endif //WRAPMODE_H
