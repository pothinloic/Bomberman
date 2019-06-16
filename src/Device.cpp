/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Device
*/

#include <irrlicht.h>
#include "../include/Device.hpp"

Device::Device()
{
    const irr::core::dimension2d<irr::u32> dim = irr::core::dimension2d<irr::u32>(1600, 900);

    _device = createDevice(irr::video::EDT_OPENGL, dim, 16, false, false, false, &_key);
    _device->setWindowCaption(L"Bomberman");
    _device->getCursorControl()->setVisible(false);
    _driver = _device->getVideoDriver();
    _smgr = _device->getSceneManager();
    irr::scene::ICameraSceneNode *camera = _smgr->addCameraSceneNode(0, irr::core::vector3df(90.0f, 75.0f, 160.0f), irr::core::vector3df(90.0f, 75.0f, 0.0f));
    _guienv = _device->getGUIEnvironment();
    _inGame = false;
    _inSettings = false;
    _switchMenu = false;
#ifdef __linux__
    _music = new sf::Music;
    playMusic("music/menuintro.ogg", false);
#endif
}

void    Device::load(unsigned int flag)
{
    irr::video::SColor  color(255, 140, 230, 220);
#ifdef __linux__
    if (!isInGame())
        playMusic("music/menuloop.ogg", true);
    else
        playMusic("music/gameloop.ogg", true);
#endif
    if (_key.getVectorKey()[e_action::PAUSE] == true) {
        _device->drop();
        exit(0);
    }
    if (_inGame == false) {
        switch (flag) {
        case (PLAY_ON):
            _inGame = true;
#ifdef __linux__
            _music->stop();
            playMusic("music/gameintro.ogg", false);
#endif
            break;
        case (SET_ON):
            _guienv->addMessageBox(L"Settings", L"Not available");
            break;
        case (CRED_ON):
            _guienv->addMessageBox(L"Credits", L"Not available");
            break;
        case (QUIT_NOW):
            exit(0);
#ifdef __linux__
            this->destroyMusic();
#endif
        default:
            break;
        }
    }
    else {
        _driver->beginScene(true, true, color);
        _smgr->drawAll();
    }
    _guienv->drawAll();
    _driver->endScene();
}

void    Device::unSwitchMenu(void)
{
    _switchMenu = false;
}

void    Device::stopMusic(void)
{
#ifdef __linux__
    _music->stop();
#endif
}

void    Device::playMusic(std::string path, bool loop)
{
#ifdef __linux__
    if (_music->getStatus() == sf::Music::Status::Stopped && _music->openFromFile(path.c_str())) {
        _music->setLoop(loop);
        _music->play();
    }
#endif
}

void    Device::destroyMusic(void)
{
#ifdef __linux__
    _music->stop();
    delete _music;
    MySleep sleep(100);
#endif
}

Device::~Device()
{
    _device->drop();
#ifdef __linux__
    this->destroyMusic();
#endif
    exit(0);
}
