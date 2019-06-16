/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Fire
*/

#include "../include/Fire.hpp"

#include <iostream>
#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;

Fire::Fire(Device &device, const irr::core::vector3df pos)
{
	_ttd = (device.getTime() + 2000);
	_fire =
		device.getSmgr()->addParticleSystemSceneNode(false);
	scene::IParticleEmitter*	em = _fire->createBoxEmitter(
		core::aabbox3d<f32>(-6, 0, -7, 7, 1, 7),
		core::vector3df(0.0f, 0.01f, 0.0f),
		80, 600,
		video::SColor(0, 0, 0, 0),
		video::SColor(0, 255, 255, 255),
		600, 1200, 0,
		core::dimension2df(0.0f, 0.0f),
		core::dimension2df(30.0f, 30.0f));
	_fire->setEmitter(em);
	em->drop();

	scene::IParticleAffector*	paf = _fire->createFadeOutParticleAffector();

	_fire->addAffector(paf);
	paf->drop();

	_fire->setPosition(pos);
	_fire->setScale(core::vector3df(2, 2, 2));
	_fire->setMaterialFlag(video::EMF_LIGHTING, false);
	_fire->setMaterialFlag(video::EMF_ZWRITE_ENABLE, false);
	_fire->setMaterialTexture(0, device.getDriver()->getTexture("./media/Fire/fire.bmp"));
	_fire->setMaterialType(video::EMT_TRANSPARENT_ADD_COLOR);
}

bool	Fire::remove(void)
{
	if (_fire != nullptr) {
		_fire->remove();
		_fire = nullptr;
		return (true);
	}
	return (false);
}

Fire::~Fire()
{
}

void	Fire::load(Device &device)
{
}