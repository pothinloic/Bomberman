/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Device
*/

#ifndef DEVICE_HPP_
#define DEVICE_HPP_

#include <irrlicht.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "IEntities.hpp"
#include "Key.hpp"
#include "Sleep.hpp"
#ifdef __linux__
#include <SFML/Audio.hpp>
#endif

class Device
{
public:
    Device();
    ~Device();

    KeyManagement   getKey(void) const { return(_key); };
    irr::IrrlichtDevice *getDevice(void) const { return(_device); };
    irr::video::IVideoDriver    *getDriver(void) const { return (_driver); };
    irr::gui::IGUIEnvironment   *getGuienv(void) const { return(_guienv); };
	irr::scene::ISceneManager		*getSmgr(void) const { return (_smgr); };
    void    load(unsigned int);
    bool    switchMenu(void) const { return (_switchMenu); };
    void    unSwitchMenu(void);
    void    stopMusic(void);
    void    playMusic(std::string, bool);
    int getTime() { return (_device->getTimer()->getTime()); };
    void    checkBomb(Device &, const std::vector <bool> &, const irr::core::vector3df &);
    bool    isInGame(void) const { return (_inGame); };
    void    setGame(const bool &game) { _inGame = game; };
    void    destroyMusic(void);

private:
    irr::IrrlichtDevice *_device;
    KeyManagement   _key;
    irr::video::IVideoDriver    *_driver;
    irr::scene::ISceneManager   *_smgr;
    irr::gui::IGUIEnvironment   *_guienv;
    bool    _inGame;
    bool    _inSettings;
    bool    _switchMenu;
#ifdef __linux__
    sf::Music *_music;
#endif
};

#endif // !DEVICE_HPP_
