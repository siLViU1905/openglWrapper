#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H
#include <cstdint>

#include "DataType.h"

namespace GL
{
    class VertexArray
    {
        uint32_t m_Vao;

    public:
        VertexArray();

        constexpr VertexArray(VertexArray &&vao) noexcept : m_Vao(vao.m_Vao)
        {
            vao.m_Vao = 0;
        }

        VertexArray &operator=(VertexArray &&vao)
            noexcept;

        constexpr uint32_t getVao() const { return m_Vao; }

        void attribPointer(uint32_t index, int size, DataType type, bool normalized, int stride, const void* pointer);

        void enableAttrib(uint32_t index);

        void bind() const;

        void unbind() const;

        ~VertexArray();
    };

    typedef VertexArray VAO;

} // GL



#endif //VERTEXARRAY_H
