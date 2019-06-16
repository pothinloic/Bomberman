/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Image
*/

#include "../include/Image.hpp"

Image::Image(Explode &infos)
{
    set_position(infos.next());
    _basic = infos.next();
}

Image::~Image()
{}

void    Image::load(irr::video::IVideoDriver *driver)
{
    irr::video::ITexture* images = driver->getTexture(_basic.c_str());
    driver->draw2DImage(images, _pos);
}

static void init_pos(Explode &infos, int &x, int &y)
{
    try {
        x = std::stoi(infos.actual().c_str());
    }   catch (const std::invalid_argument &ia) {
        std::cerr << "Invalid argument: " << ia.what() << std::endl;
        x = 0;
    }
    try {
        y = std::stoi(infos.next().c_str());
    }   catch (const std::invalid_argument& ia) {
        std::cerr << "Invalid argument: " << ia.what() << std::endl;
        y = 0;
    }
}

void    Image::set_position(const std::string &str)
{
    Explode infos(str, ":");
    int x = 0;
    int y = 0;

    init_pos(infos, x, y);
    _pos = irr::core::position2d<irr::s32>(x, y);
}