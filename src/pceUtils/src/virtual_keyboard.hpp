#ifndef VIRT_KEYBOARD_HPP
#define VIRT_KEYBOARD_HPP

#include <string>
#include <vector>
#include <unordered_map>

#include <SDL2/SDL.h>
#include <pceLogger/pceLogger.hpp>


namespace {
constexpr const char* log_name_vk = "virtual_keyboard";
}



namespace pce {


enum class Key : uint32_t
{
    Right = 0x1000,
    Left  = 0x01,
    Up    = 0x02,
    Down  = 0x04,
    Space = 0x08,
    w     = 0x10,
    s     = 0x20,
    a     = 0x40,
    d     = 0x80,
    r     = 0x100,
    f     = 0x200,
    x     = 0x400,
    e     = 0x800,
    q     = 0x2000
};
const std::unordered_map<Key, std::string> key_to_str = {
    { Key::Right, "Right" },
    { Key::Left,  "Left" },
    { Key::Up,    "Up" },
    { Key::Down,  "Down" },
    { Key::w,     "w" },
    { Key::s,     "s" },
    { Key::a,     "a" },
    { Key::d,     "d" },
    { Key::r,     "r" },
    { Key::f,     "f" },
    { Key::x,     "x" },
    { Key::e,     "e" },
    { Key::q,     "q" }
};


class VirtualKeyboard
{
    uint32_t state_ = 0;
public:
    inline bool pressed(Key key) const
    {
        return static_cast<bool>(
            state_ & static_cast<int32_t>(key)
        );
    }

    void updateStatusSDL(const std::vector<SDL_Event>& frame_events)
    {
        const std::unordered_map<SDL_Keycode, Key> sdl_keycode_to_key = {
            { SDLK_RIGHT, Key::Right },
            { SDLK_LEFT,  Key::Left },
            { SDLK_UP,    Key::Up },
            { SDLK_DOWN,  Key::Down },
            { SDLK_w,     Key::w },
            { SDLK_s,     Key::s },
            { SDLK_a,     Key::a },
            { SDLK_d,     Key::d },
            { SDLK_r,     Key::r },
            { SDLK_f,     Key::f },
            { SDLK_x,     Key::x },
            { SDLK_e,     Key::e },
            { SDLK_q,     Key::q }
        };
        //state_ = 0;
        //LOG_DEBUG(log_name_vk) << "number of frame events: " << int(frame_events.size());
        for (int i = 0; i < frame_events.size(); i++)
        {
            const auto itrSdlKeyToKey = sdl_keycode_to_key.find(frame_events[i].key.keysym.sym);
            if (itrSdlKeyToKey == sdl_keycode_to_key.end())
            {
                continue;
            }
            /* check specifically for key press event */
            uint32_t value = 2; //!< 2 is arbitrary invalid value; see below
            if ( frame_events[i].type == SDL_KEYDOWN )
            {
                //LOG_DEBUG(log_name_vk) << "key down: " << key_to_str.at(itrSdlKeyToKey->second);
                value = 1;
            }
            else if ( frame_events[i].type == SDL_KEYUP )
            {
                //LOG_DEBUG(log_name_vk) << "key up: " << key_to_str.at(itrSdlKeyToKey->second);
                value = 0;
            }

            if (value == 2)
                return;
            state_ &= ~static_cast<uint32_t>(itrSdlKeyToKey->second);
            state_ |= value * static_cast<uint32_t>(itrSdlKeyToKey->second);
        }
    }
};

} /* namespace pce */

#endif /* #ifndef VIRT_KEYBOARD_HPP */
