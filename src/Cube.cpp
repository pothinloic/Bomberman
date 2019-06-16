/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Cube
*/

#include "../include/Cube.hpp"

Cube::Cube(Device &device, vector3df &pos, const std::string &texture)
{
	_pos = pos;
	_cube = device.getSmgr()->addCubeSceneNode(15.0f, 0, -1, _pos);
	_cube->setMaterialFlag(EMF_LIGHTING, false);
	_texture = device.getDriver()->getTexture(texture.c_str());
    _cube->setMaterialTexture(0, _texture);
}

Cube::~Cube()
{
}

void	Cube::setColision(Device &device, scene::IAnimatedMeshSceneNode *player)
{
	irr::scene::ITriangleSelector* selector = 0;

	selector = device.getSmgr()->createOctreeTriangleSelector(_cube->getMesh(), _cube, 128);
	_cube->setTriangleSelector(selector);
	if (selector) {
        scene::ISceneNodeAnimator *anim = device.getSmgr()->createCollisionResponseAnimator(
            selector, player, core::vector3df(5, 5, 0.01),
		                      core::vector3df(0, 0, 0),
                              core::vector3df(0, 0, 0));
		selector->drop();
		player->addAnimator(anim);
		anim->drop();
	}
}

void    Cube::destroy()
{
    if (_cube != nullptr) {
        _cube->remove();
        _cube = nullptr;
    }
}

void	Cube::load(Device &device)
{
}