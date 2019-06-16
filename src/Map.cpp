/*
** EPITECH PROJECT, 2019
** bomber_map
** File description:
** Map
*/

#include <iostream>
#include <time.h>
#include "../include/Map.hpp"

static int notSpawn(int x, int y)
{
    if (x < 2 && y < 2)
        return (0);
    if (x > 10 && y < 2)
        return (0);
    if (x < 2 && y > 8)
        return (0);
    if (x > 10 && y > 8)
        return (0);
    return (1);
}

void    Map::randomizeMap()
{
    int nbCrates;
    int x;
    int y;

    srand(time(0));
    nbCrates = 80 + (rand() % 4) + 1;
    while (nbCrates != 0) {
        x = rand() % 13;
        y = rand() % 11;
        if (_tiles[y * 13 + x]->getHasCrate() == 0 && _tiles[y * 13 + x]->getIsSolid() == 0
            && notSpawn(x, y) == 1) {
            _tiles [y * 13 + x]->setCrate(1);
            nbCrates--;
        }
    }
}

void    Map::generateWalls(Device &device)
{
    for (int i = -1; i < 11; i++) {
        _walls.push_back(new Tile(device, vector3df(-1 * 15, i * 15, 0), true, false));
        _walls.push_back(new Tile(device, vector3df(13 * 15, i * 15, 0), true, false));
    }
    for (int i = -1; i < 14; i++) {
        _walls.push_back(new Tile(device, vector3df(i * 15, -1 * 15, 0), true, false));
        _walls.push_back(new Tile(device, vector3df(i * 15, 11 * 15, 0), true, false));
    }
}

void    Map::generateMap(Device &device)
{
    for (int y = 0; y < 11; y++) {
        for (int x = 0; x < 13; x++) {
            if ((x % 2 != 0) && (y % 2 == 1))
                _tiles.push_back(new Tile(device, vector3df((x * 15), (y * 15), 0), true, false));
            else
                _tiles.push_back(new Tile(device, vector3df((x * 15), (y * 15), 0), false, false));
        }
    }
}

void    Map::linkTiles()
{
    for (int y = 0; y < 11; y++) {
        for (int x = 0; x < 13; x++) {
            if (y == 0)
                _tiles[y * 13 + x]->setAbove(nullptr);
            else
                _tiles[y * 13 + x]->setAbove(_tiles[((y - 1) * 13 + x)]);
            if (y == 10)
                _tiles[y * 13 + x]->setUnder(nullptr);
            else
                _tiles[y * 13 + x]->setUnder(_tiles[((y + 1) * 13 + x)]);
            if (x == 0)
                _tiles[y * 13 + x]->setLeft(nullptr);
            else
                _tiles[y * 13 + x]->setLeft(_tiles[(y * 13 + x - 1)]);
            if (x == 12)
                _tiles[y * 13 + x]->setRight(nullptr);
            else
                _tiles[y * 13 + x]->setRight(_tiles[(y * 13 + x + 1)]);
        }
    }
}

void    Map::displayMapCratesConsole()
{
    for (int y = 0; y < 11; y++) {
        for (int x = 0; x < 13; x++) {
            std::cout << _tiles[(y * 13) + x]->getHasCrate();
        }
        std::cout << std::endl;
    }
}

void    Map::displayMapWallsConsole()
{
    for (int y = 0; y < 11; y++) {
        for (int x = 0; x < 13; x++) {
            std::cout << _tiles[(y * 13) + x]->getIsSolid();
        }
        std::cout << std::endl;
    }
}

void    Map::displayMapConsole()
{
    for (int y = 0; y < 11; y++) {
        for (int x = 0; x < 13; x++) {
            if (_tiles[(y * 13) + x]->getIsSolid())
                std::cout << "o";
            else if (_tiles[(y * 13) + x]->getHasCrate())
                std::cout << "x";
            else
                std::cout << ".";
        }
        std::cout << std::endl;
    }
}

void    Map::load(Device &device, irr::scene::IAnimatedMeshSceneNode *player1)
{
    for (int i = _walls.size() - 1; i != -1; i--)
        _walls[i]->updateTiles(device);
    for (int i = _tiles.size() - 1; i != -1; i--)
        _tiles[i]->updateTiles(device);
    setCubeColision(device, player1);
}

void    Map::loadFloor(Device &device)
{
    for (int i = _tiles.size() - 1; i != -1; i--)
        _tiles[i]->setFloor(device);
}

bool	Map::setCubeColision(Device &device, irr::scene::IAnimatedMeshSceneNode *player)
{
    if (player == nullptr)
        return (true);
    player->removeAnimators();
	for (int i = 0; i != _walls.size(); i++) {
		Cube *cube = _walls[i]->getCube();
		if (cube != nullptr)
			cube->setColision(device, player);
	}
    for (int i = _tiles.size() - 1; i >= 0; i--) {
        Cube *cube = _tiles[i]->getCube();
        if (cube != nullptr)
            cube->setColision(device, player);
    }
    return (false);
}

static int round_value(const int &i)
{
    int j = 0;

    if (i < 0)
        return (0);
    for (j = 0; ((j * 15) < i) && (((j + 1) * 15) < i); j++);
    int before = j * 15;
    int after = (j + 1) * 15;
    return ((i - before) < (after - i) ? before : after);
}

Tile    *Map::findTile(const irr::core::vector3df &player)
{
    irr::core::vector3df tile;

    for (int i = 0; i != _tiles.size(); i++) {
        tile = _tiles[i]->getPos();
        if (tile.X == round_value(player.X) &&
            tile.Y == round_value(player.Y) &&
            tile.Z == round_value(player.Z))
            return (_tiles[i]);
    }
}

bool    Map::checkBomb(Device &device, const std::vector<bool> &key, Character *player)
{
    std::vector<bool> destroy;

    if (key[e_action::BOMB] == true && player->hasBomb() == false)
        findTile(player->getPosition())->setBomb(device, player);
    for (int i = 0; i != _tiles.size(); i++)
        destroy.push_back(_tiles[i]->checkBomb(device, player));
    for (int i = 0; i != destroy.size(); i++) {
        if (destroy[i] == true)
            return (true);
    }
    return (false);
}

Map::Map(Device &device, irr::scene::IAnimatedMeshSceneNode *player)
{
    generateWalls(device);
    generateMap(device);
    linkTiles();
    randomizeMap();
    loadFloor(device);
    load(device, player);
}

void    Map::destroy()
{
    for (int i = _walls.size() - 1; i != -1; i--) {
        _walls[i]->destroyCube();
        _tiles[i]->destroyFloor();
    }
    for (int i = _tiles.size() - 1; i != -1; i--) {
        _tiles[i]->destroyCube();
        _tiles[i]->destroyFloor();
    }
}

Map::~Map()
{
}
