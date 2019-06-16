#ifndef IENTITIES_HPP_
#define IENTITIES_HPP_

#include <irrlicht.h>
#include "Explode.hpp"
#include "Device.hpp"

typedef enum e_game
{
    PLAY_ON = 0,
    PLAY_OFF,
    SET_ON,
    SET_OFF,
    CRED_ON,
    CRED_OFF,
    QUIT_NOW
}   game_t;

class IEntities
{
public:
    ~IEntities() = default;
    virtual void    load(irr::video::IVideoDriver *) = 0;
    virtual void    setSelected(const bool &) = 0;
    virtual bool    isButton() const = 0;
    virtual game_t    launchAction(irr::IrrlichtDevice *) = 0;

protected:
    irr::core::position2d<irr::s32>	_pos;
    std::string _basic;
private:
};

#endif // !IENTITIES_HPP_
