#ifndef SHADER_H
#define SHADER_H
#include <cstdint>

#include "../Logger/Logger.h"
#include "ShaderType.h"

namespace GL
{
    class Shader
    {
        uint32_t m_Program;
        uint32_t m_VertexShader;
        uint32_t m_FragmentShader;

        sgl::Logger* logger;

    public:
        Shader();

        Shader(const Shader&) = delete;

        Shader(Shader&& shader) noexcept;

        Shader(sgl::Logger& logger);

        Shader& operator=(const Shader&) = delete;

        Shader& operator=(Shader&& shader) noexcept ;

        bool compile(ShaderType type, const std::string& path);

        bool link();

        void bind() const;

        void unbind() const;

        void setUniformInt(const std::string& name, int value) const;

        void setUniformVec3(const std::string& name, const float* ptr, int count = 1) const;



        ~Shader();
    };
} // GL

#endif //SHADER_H
