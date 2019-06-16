#ifndef BOMB_HPP_
#define BOMB_HPP_

#include <iostream>
#include <irrlicht.h>
#include "Device.hpp"
#include "Fire.hpp"
#include "Character.hpp"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;

class Bomb {
public:
	Bomb(Device &, const irr::core::vector3df);
	~Bomb();

	void	load(Device &);
    bool    explode(Device &);

private:
	irr::core::vector3df _pos;

	ITexture *_texture;
	ISceneNode *_bomb;
    int _tte;
};

#endif // !BOMB_HPP_