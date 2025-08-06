//
// Created by Silviu on 06.08.2025.
//

#ifndef FWHP_H
#define FWHP_H
#include "TextureFormat.h"

namespace GL
{
    struct FWHP
    {
        TextureFormat format;
        int width;
        int height;
        uint8_t *pixels;

        FWHP();
    };
} // GL

#endif //FWHP_H
