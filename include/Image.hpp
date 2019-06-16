/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Image
*/

#ifndef IMAGE_HPP_
#define IMAGE_HPP_

#include "IEntities.hpp"
#include "Device.hpp"

class Image : public IEntities
{
public:
    Image(Explode &);
    ~Image();

    void    load(irr::video::IVideoDriver *);
    void    setSelected(const bool &) {};
    bool    isButton() const { return (false); };
    game_t    launchAction(irr::IrrlichtDevice *) { return (PLAY_OFF); };

private:
    void    set_position(const std::string &str);
    irr::core::position2d<irr::s32>	_pos;
    std::string _basic;
};

#endif // !IMAGE_HPP_