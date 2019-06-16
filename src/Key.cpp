/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Key
*/

#include <irrlicht.h>
#include <IEventReceiver.h>
#include "../include/Key.hpp"

using namespace irr;

KeyManagement::KeyManagement()
{
    for (u32 i = 0; i < KEY_KEY_CODES_COUNT; ++i)
        KeyIsDown[i] = false;
    for (int i = 0; i != 7; i++)
        _vectorKey.push_back(false);
    _up = KEY_KEY_Z;
    _down = KEY_KEY_S;
    _left = KEY_KEY_Q;
    _right = KEY_KEY_D;
    _bomb = KEY_SPACE;
    _pause = KEY_ESCAPE;
}

KeyManagement::~KeyManagement()
{
}

bool KeyManagement::OnEvent(const SEvent& event)
{
    if (event.EventType == EET_KEY_INPUT_EVENT) {
        if (event.KeyInput.Key == _up)
            _vectorKey[e_action::UP] = event.KeyInput.PressedDown;
        if (event.KeyInput.Key == _down)
            _vectorKey[e_action::DOWN] = event.KeyInput.PressedDown;
        if (event.KeyInput.Key == _left)
            _vectorKey[e_action::LEFT] = event.KeyInput.PressedDown;
        if (event.KeyInput.Key == _right)
            _vectorKey[e_action::RIGHT] = event.KeyInput.PressedDown;
        if (event.KeyInput.Key == _bomb)
            _vectorKey[e_action::BOMB] = event.KeyInput.PressedDown;
        if (event.KeyInput.Key == _pause)
            _vectorKey[e_action::PAUSE] = event.KeyInput.PressedDown;
    }
    return (false);
}

bool KeyManagement::IsKeyDown(EKEY_CODE keyCode)
{
    return KeyIsDown[keyCode];
}

void KeyManagement::clearVector()
{
    for (int i = 0; i != _vectorKey.size(); i++)
        _vectorKey[i] = false;
}

e_action KeyManagement::getKey()
{
    if (IsKeyDown(_up))
        return (UP);
    if (IsKeyDown(_down))
        return (DOWN);
    if (IsKeyDown(_left))
        return (LEFT);
    if (IsKeyDown(_right))
        return (RIGHT);
    if (IsKeyDown(_bomb))
        return (BOMB);
    if (IsKeyDown(_pause))
        return (PAUSE);
    else
        return (NONE);
}
