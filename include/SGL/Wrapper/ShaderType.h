#ifndef SHADERTYPE_H
#define SHADERTYPE_H
#include <cstdint>

#include "../../GL/glad.h"

namespace GL
{
    enum class ShaderType : uint32_t
    {
        VERTEX = GL_VERTEX_SHADER,
        FRAGMENT = GL_FRAGMENT_SHADER
    };
} // GL

#endif //SHADERTYPE_H
