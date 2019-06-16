#ifndef CUBE_HPP_
#define CUBE_HPP_

#include <iostream>
#include <irrlicht.h>
#include "../include/Device.hpp"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;

class Cube {
public:
	Cube(Device &, vector3df &, const std::string &r);
	~Cube();

	void	load(Device &);
	bool	isBroken() { return (_broken); };
	void	setColision(Device &device, scene::IAnimatedMeshSceneNode *player);
    void    destroy();

private:
    vector3df _pos;

	ITexture *_texture;
	IMeshSceneNode *_cube;
	bool	_broken;
};

#endif // !CUBE_HPP_
