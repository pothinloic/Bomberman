#include <iostream>
#include <irrlicht.h>
#include "../include/menu.hpp"

using namespace irr;

using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

int	main()
{
	Menu	mainMenu("../../conf/menu/main.conf");
	const dimension2d<u32> dim = dimension2d<u32>(1024, 1280);
	IrrlichtDevice *device = createDevice(EDT_SOFTWARE, dim, 16, false, false, false, 0);

	device->setWindowCaption(L"Bomberman");
	IVideoDriver* driver = device->getVideoDriver();
	ISceneManager* smgr = device->getSceneManager();
	IGUIEnvironment* guienv = device->getGUIEnvironment();

	while (device->run())
	{
		const dimension2d<u32> ricdim = dimension2d<u32>(480, 360);
		driver->beginScene(true, true, SColor(246, 150, 255, 143));
		video::ITexture* images = driver->getTexture("../../media/ricardo.jpg");
		driver->draw2DImage(images, core::position2d<s32>(50, 50));

		guienv->drawAll();

		driver->endScene();
	}
	device->drop();
	return 0;
}