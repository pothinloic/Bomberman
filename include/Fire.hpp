#ifndef FIRE_HPP_
#define FIRE_HPP_

#include <iostream>
#include <irrlicht.h>
#include "../include/Device.hpp"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;

class Fire {
public:
	Fire(Device &, const irr::core::vector3df);
	~Fire();

	void	load(Device &);
	int		get_ttd(void) const { return(_ttd); };
	bool	remove(void);

private:
	int		_ttd;
	IParticleSystemSceneNode *_fire;
};

#endif // !FIRE_HPP_