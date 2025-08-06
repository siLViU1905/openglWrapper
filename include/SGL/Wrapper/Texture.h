#ifndef TEXTURE_H
#define TEXTURE_H
#include <cstdint>
#include <string>

#include "TextureFormat.h"
#include "TextureParam.h"
#include "FilterMode.h"
#include "TextureType.h"
#include "../System/stb_image.h"
#include "FWHP.h"
#include "WrapMode.h"

namespace GL
{
    template<TextureType type>
    class Texture
    {
        uint32_t m_ID;

    public:
        Texture()
        {
            glGenTextures(1, &m_ID);
        }

        Texture(const Texture &) = delete;

        Texture(Texture &&texture) noexcept: m_ID(texture.m_ID)
        {
            texture.m_ID = 0;
        }

        Texture &operator=(const Texture &) = delete;

        Texture &operator=(Texture &&texture) noexcept
        {
            m_ID = texture.m_ID;

            texture.m_ID = 0;

            return *this;
        }

        constexpr uint32_t getID() const { return m_ID; }

        void bind() const
        {
            glBindTexture(static_cast<uint32_t>(type), m_ID);
        }

        void unbind() const
        {
            glBindTexture(static_cast<uint32_t>(type), 0);
        }

        FWHP load(const std::string &path, TextureFormat desiredFormat = TextureFormat::NONE)
        {
            int desiredChannels = 0;

            switch (desiredFormat)
            {
                case TextureFormat::RG:
                    desiredChannels = 2;
                    break;

                case TextureFormat::RGB:
                    desiredChannels = 3;
                    break;

                case TextureFormat::RGBA:
                    desiredChannels = 4;
                    break;
            }

            FWHP fwhp;

            int channels;

            fwhp.pixels = stbi_load(path.c_str(), &fwhp.width, &fwhp.height, &channels, desiredChannels);

            if (!fwhp.pixels)
                return fwhp;

            switch (channels)
            {
                case 2:
                    fwhp.format = TextureFormat::RG;
                    break;

                case 3:
                    fwhp.format = TextureFormat::RGB;
                    break;

                case 4:
                    fwhp.format = TextureFormat::RGBA;
                    break;
            }

            return fwhp;
        }

        void parameter(TextureParam param, FilterMode mode) const
        {
            glTexParameteri(static_cast<uint32_t>(type), static_cast<uint32_t>(param), static_cast<int>(mode));
        }

        void parameter(TextureParam param, WrapMode mode) const
        {
            glTexParameteri(static_cast<uint32_t>(type), static_cast<uint32_t>(param), static_cast<int>(mode));
        }

        ~Texture()
        {
            if (m_ID)
                glDeleteTextures(1, &m_ID);
        }
    };

    typedef Texture<TextureType::T_1D> Texture1D;

    typedef Texture<TextureType::T_2D> Texture2D;

    typedef Texture<TextureType::T_3D> Texture3D;

    typedef Texture<TextureType::T_1D_ARRAY> Texture1DArray;

    typedef Texture<TextureType::T_2D_ARRAY> Texture2DArray;

    /*typedef Texture<TextureType::T_2D_MULTISAMPLE> Texture2DMultisample;

    typedef Texture<TextureType::T_2D_MULTISAMPLE_ARRAY> Texture2DMultisampleArray;*/


} // GL

#endif //TEXTURE_H
