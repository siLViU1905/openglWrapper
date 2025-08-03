#include "Shader.h"

#include <fstream>

namespace GL
{
    Shader::Shader(): logger(nullptr)
    {
        m_Program = glCreateProgram();
    }

    Shader::Shader(sgl::Logger &logger): logger(&logger)
    {
        m_Program = glCreateProgram();
    }

    bool Shader::compile(ShaderType type, const std::string &path)
    {
        std::ifstream file(path, std::ios::binary | std::ios::ate);

        if (file.is_open())
        {
            size_t shaderSize = file.tellg();
            char *shaderCode = new char[shaderSize + 1];
            shaderCode[shaderSize] = 0;
            file.seekg(0);
            file.read(shaderCode, shaderSize);
            file.close();

            if (type == ShaderType::VERTEX)
            {
                m_VertexShader = glCreateShader(static_cast<uint32_t>(type));
                glShaderSource(m_VertexShader, 1, &shaderCode, nullptr);
                glCompileShader(m_VertexShader);

                int success;
                char infoLog[512];
                glGetShaderiv(m_VertexShader, GL_COMPILE_STATUS, &success);

                if (!success)
                {
                    glGetShaderInfoLog(m_VertexShader, 512, nullptr, infoLog);
                    if (logger)
                        logger->log(infoLog);
                    return false;
                }
            } else
            {
                m_FragmentShader = glCreateShader(static_cast<uint32_t>(type));

                m_FragmentShader = glCreateShader(static_cast<uint32_t>(type));
                glShaderSource(m_FragmentShader, 1, &shaderCode, nullptr);
                glCompileShader(m_FragmentShader);

                int success;
                char infoLog[512];
                glGetShaderiv(m_FragmentShader, GL_COMPILE_STATUS, &success);

                if (!success)
                {
                    glGetShaderInfoLog(m_FragmentShader, 512, nullptr, infoLog);
                    if (logger)
                        logger->log(infoLog);
                    return false;
                }
            }
        } else
        {
            if (logger)
                logger->log("File not found");
            return false;
        }

        return true;
    }

    bool Shader::link()
    {
        glAttachShader(m_Program, m_VertexShader);
        glAttachShader(m_Program, m_FragmentShader);

        glLinkProgram(m_Program);

        int success;
        char infoLog[512];

        glGetProgramiv(m_Program, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(m_Program, 512, nullptr, infoLog);
            if (logger)
                logger->log(infoLog);
            return false;
        }

        glDeleteShader(m_VertexShader);
        glDeleteShader(m_FragmentShader);

        return true;
    }

    void Shader::bind() const
    {
        glUseProgram(m_Program);
    }

    void Shader::unbind() const
    {
        glUseProgram(0);
    }

    void Shader::setUniformVec3(const std::string &name, const float *ptr, int count) const
    {
        glUniform3fv(glGetUniformLocation(m_Program, name.c_str()),count, ptr);
    }

    Shader::~Shader()
    {
        glDeleteProgram(m_Program);
    }
} // GL
