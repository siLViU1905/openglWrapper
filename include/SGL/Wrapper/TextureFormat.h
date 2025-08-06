#ifndef TEXTUREFORMAT_H
#define TEXTUREFORMAT_H
#include <cstdint>

#include "../../GL/glad.h"

namespace GL
{
    enum class TextureFormat : uint32_t
    {
        NONE,
        RED = GL_RED,
        RG = GL_RG,
        RGB = GL_RGB,
        RGBA = GL_RGBA
    };
} // GL

#endif //TEXTUREFORMAT_H
