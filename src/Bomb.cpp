/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Bomb
*/

#include "../include/Bomb.hpp"
#include "../include/Fire.hpp"

Bomb::Bomb(Device &device, const irr::core::vector3df pos)
{
    _tte = device.getTime() + 3000;
	_pos = pos;
	_texture = device.getDriver()->getTexture("./media/bomb/Bomb.png");
	_bomb = device.getSmgr()->addAnimatedMeshSceneNode(device.getSmgr()->getMesh("./media/bomb/Bomb.obj"));
    _bomb->setPosition(_pos);
	_bomb->setMaterialFlag(EMF_LIGHTING, false);
    _bomb->setScale(irr::core::vector3df(3, 3, 3));
    _bomb->setRotation(core::vector3df(90, 0, 0));
    _bomb->setMaterialTexture(0, _texture);
}

Bomb::~Bomb()
{
}

bool	Bomb::explode(Device &device)
{
    int time = device.getTime();
    if (_tte < time && _bomb != nullptr) {
        _bomb->remove();
        _bomb = nullptr;
        return (true);
    }
    return (false);
        
}