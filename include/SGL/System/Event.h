#ifndef EVENT_H
#define EVENT_H
#include "Keyboard.h"
#include "EventType.h"
#include "Mouse.h"
#include "WindowState.h"

namespace sgl
{
    class Event
    {
    public:
        Keyboard keyboard;

        Mouse mouse;

        WindowState windowState;

        EventType type;

        constexpr Event():type(EventType::NONE), windowState(WindowState::NONE) {}

        Event(const Event& event) = delete;

        Event& operator=(const Event& event) = delete;
    };
} // sgl

#endif //EVENT_H
