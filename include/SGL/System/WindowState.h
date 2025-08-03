#ifndef WINDOWSTATE_H
#define WINDOWSTATE_H

namespace sgl
{
    enum class WindowState
    {
        NONE,
        CLOSED,
        RESIZED,
        MAXIMIZED,
        MINIMIZED,
        GAINED_FOCUS,
        LOST_FOCUS
    };
}


#endif //WINDOWSTATE_H
