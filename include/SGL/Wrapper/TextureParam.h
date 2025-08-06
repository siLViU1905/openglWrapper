#ifndef TEXTUREPARAM_H
#define TEXTUREPARAM_H
#include <cstdint>

#include "../../GL/glad.h"

namespace GL
{
    enum class TextureParam : uint32_t
    {
        MAG_FILTER = GL_TEXTURE_MAG_FILTER,
       MIN_FILTER = GL_TEXTURE_MIN_FILTER,
       WRAP_S = GL_TEXTURE_WRAP_S,
       WRAP_T = GL_TEXTURE_WRAP_T,
       WRAP_R = GL_TEXTURE_WRAP_R
    };
} // GL

#endif //TEXTUREPARAM_H
