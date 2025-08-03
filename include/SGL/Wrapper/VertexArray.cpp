#include "VertexArray.h"
#include "../../GL/glad.h"

namespace GL
{
    VertexArray::VertexArray()
    {
        glGenVertexArrays(1, &m_Vao);
    }

    VertexArray & VertexArray::operator=(VertexArray &&vao) noexcept
    {
        m_Vao = vao.m_Vao;
        vao.m_Vao = 0;

        return *this;
    }


    void VertexArray::attribPointer(uint32_t index, int size, DataType type, bool normalized, int stride,
        const void *pointer)
    {
        glVertexAttribPointer(index, size, static_cast<uint32_t>(type),normalized, stride, pointer);
    }

    void VertexArray::enableAttrib(uint32_t index)
    {
        glEnableVertexAttribArray(index);
    }

    void VertexArray::bind() const
    {
        glBindVertexArray(m_Vao);
    }

    void VertexArray::unbind() const
    {
        glBindVertexArray(0);
    }

    VertexArray::~VertexArray()
    {
        if (m_Vao)
            glDeleteVertexArrays(1, &m_Vao);
    }
} // GL
