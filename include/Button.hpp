/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Button
*/

#ifndef BUTTON_HPP_
#define BUTTON_HPP_

#include <irrlicht.h>
#include <iostream>
#include "IEntities.hpp"
#include "Device.hpp"

enum e_type
{
    NOTHING = 0,
    QUIT,
    PLAY,
    SET,
    CRED,
    MENU,
};

class Button : public IEntities
{
	public:
		Button(Explode &infos);
		~Button();

        void    load(irr::video::IVideoDriver *);
        bool    isSelected() { return (_selected); };
        void    setSelected(const bool &status) { _selected = status; };
        bool    isButton() const { return (true); };
        game_t    launchAction(irr::IrrlichtDevice *);

	private:
        void    set_position(const std::string &);
        void    set_type(const std::string &);
        void    set_texture(const std::string &, const std::string &);
		std::string _basic;
		std::string _hover;
        irr::core::position2d<irr::s32>	_pos;
        e_type  _type;
        bool    _selected;
};

#endif // !BUTTON_HPP_
