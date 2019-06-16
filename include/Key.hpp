#ifndef KEY_HPP_
#define KEY_HPP_

#include <irrlicht.h>
#include <iostream>
#include <IEventReceiver.h>
#include <cstdio>
#include <vector>

using namespace irr;

enum e_action
{
    NONE = 0,
    UP,
    DOWN,
    LEFT,
    RIGHT,
    BOMB,
    PAUSE
};

class KeyManagement : public IEventReceiver
{
public:
    KeyManagement();
    ~KeyManagement();

    bool OnEvent(const SEvent &event);
    bool IsKeyDown(EKEY_CODE keyCode);
    e_action getKey();
    std::vector<bool> getVectorKey() const { return _vectorKey; }
    void clearVector();

private:
    bool KeyIsDown[KEY_KEY_CODES_COUNT];
    std::vector<bool> _vectorKey;
    EKEY_CODE _up;
    EKEY_CODE _down;
    EKEY_CODE _left;
    EKEY_CODE _right;
    EKEY_CODE _bomb;
    EKEY_CODE _pause;
};

#endif // !KEY_HPP_