/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Menu
*/

#ifndef MEMU_HPP_
#define MENU_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "IEntities.hpp"
#include "Key.hpp"

class Menu
{
	public:
		Menu(const std::string &);
		~Menu();
        void    load(irr::video::IVideoDriver *);
        int getPos() { return (_pos); };
        IEntities *getButton() { return (_buttons[_pos]); };
        void    next();
        void    previous();
		void	setDisplay(bool disp) { _display = disp; };
        e_game    checkKey(KeyManagement, Device &);

	private:
		std::vector<IEntities *>    _buttons;
        KeyManagement   _key;
        unsigned int _pos;
        int _ttw;
        bool    _display;
};
#endif // !MENU_HPP_
