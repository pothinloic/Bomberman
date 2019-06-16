/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** main
*/

#include <iostream>
#include <irrlicht.h>
#include "../include/Device.hpp"
#include "../include/Menu.hpp"
#include "../include/Cube.hpp"
#include "../include/Map.hpp"
#include "../include/Character.hpp"
#include "../include/Fire.hpp"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;

int	main()
{
    Device device;
    Menu    *menu = new Menu("./conf/menu/main.conf");
    Character   *player1 = new Character("./media/Character/model/Bomberman.MD3", "./media/Character/texture/WhiteBombermanTextures.png", device);
    Map *map = new Map(device, player1->getCharacter());
    bool reset = false;
    int ttw = 0;

    while (device.getDevice()->run()) {
        if (device.switchMenu()) {
            device.unSwitchMenu();
            menu = new Menu("./conf/menu/settings.conf");
        }
        if (!device.isInGame()) {
            if (reset == true) {
                player1 = new Character("./media/Character/model/Bomberman.MD3", "./media/Character/texture/WhiteBombermanTextures.png", device);
                map->destroy();
                map = new Map(device, player1->getCharacter());
                reset = false;
            }
            menu->load(device.getDriver());
            device.load(menu->checkKey(device.getKey(), device));
            ttw = device.getTime() + 1000;
        }
        if (device.isInGame()) {
            device.load(device.getKey().getKey());
            player1->walk(device);
            if (ttw < device.getTime() &&
                map->checkBomb(device, device.getKey().getVectorKey(), player1))
                reset = map->setCubeColision(device, player1->getCharacter());
        }
    }
    device.getDevice()->drop();
    return (0);
}
