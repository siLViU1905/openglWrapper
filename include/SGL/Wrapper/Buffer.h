#ifndef BUFFERBASE_H
#define BUFFERBASE_H
#include <cstdint>
#include "BufferType.h"
#include "BufferUsage.h"

namespace GL
{
    template<BufferType type>
    class Buffer
    {
        uint32_t m_Buffer;

        BufferUsage m_Usage;

    public:
        Buffer(): m_Usage(BufferUsage::STATIC)
        {
            glGenBuffers(1, &m_Buffer);
        }

        Buffer(BufferUsage usage): m_Usage(usage)
        {
            glGenBuffers(1, &m_Buffer);
        }

        Buffer(const Buffer& buffer) = delete;

        constexpr Buffer(Buffer &&buffer) noexcept : m_Buffer(buffer.m_Buffer),
                                                     m_Usage(buffer.m_Usage)
        {
            buffer.m_Buffer = 0;
        }

        Buffer& operator=(const Buffer& buffer) = delete;

        Buffer &operator=(Buffer &&buffer) noexcept
        {
            m_Buffer = buffer.m_Buffer;
            m_Usage = buffer.m_Usage;

            buffer.m_Buffer = 0;

            return *this;
        }

        constexpr uint32_t getBuffer() const { return m_Buffer; }

        void setUsage(BufferUsage usage)
        {
            m_Usage = usage;
        }

        constexpr BufferUsage getUsage() const { return m_Usage; }

        void bind() const
        {
            glBindBuffer(static_cast<uint32_t>(type), m_Buffer);
        }

        void unbind() const
        {
            glBindBuffer(static_cast<uint32_t>(type), 0);
        }

        template<typename Ty>
        void data(const Ty *data, uint32_t size)
        {
            glBufferData(static_cast<uint32_t>(type), size * sizeof(Ty), data, static_cast<uint32_t>(m_Usage));
        }

        ~Buffer()
        {
            if (m_Buffer)
                glDeleteBuffers(1, &m_Buffer);
        }
    };


    typedef Buffer<BufferType::ARRAY> VBO;

    typedef Buffer<BufferType::ELEMENT_ARRAY> EBO;
} // GL

#endif //BUFFERBASE_H
