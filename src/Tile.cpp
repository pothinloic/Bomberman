/*
** EPITECH PROJECT, 2019
** bomber_map
** File description:
** Tile
*/

#include "../include/Tile.hpp"

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

void    Tile::destroyCrate(Device &device, Character *player)
{
    if ((player->getCharacter() != nullptr) && (
        round_value(player->getPosition().X) == _pos.X &&
        round_value(player->getPosition().Y) == _pos.Y &&
        round_value(player->getPosition().Z) == _pos.Z))
            player->destroy(device);
    if (_hasCrate == true && _isSolid == false) {
        _model->destroy();
        _model = nullptr;
    }
    _hasCrate = false;
    _isSolid = false;
}

void    Tile::setCrate(bool status)
{
    _hasCrate = status;
}

void    Tile::setCoordinates(int x, int y)
{
    _pos = vector3df(x, y, 0);
}

void    Tile::setLink(Tile *link, Tile *tile)
{
    link = tile;
}

static  std::string format_texture(const std::string &str)
{
    return ("./media/cube/" + str + ".png");
}

void    Tile::setFloor(Device &device)
{
    vector3df   vector(_pos.X, _pos.Y, -15);
    _floor = new Cube(device, vector, format_texture("floor"));
}

void    Tile::updateTiles(Device &device)
{
    if (_hasCrate == true || _isSolid == true)
        _model = new Cube(device, _pos, _texture);
    else
        _model = nullptr;
}

Tile::Tile(Device &device, const irr::core::vector3df &pos, const bool &wall, const bool &crate)
{
    _isSolid = wall;
    _hasCrate = crate;
    _pos = pos;
    _texture = format_texture((_isSolid == true) ? "iron" : "wood");
    _bomb = nullptr;
    _fire = nullptr;
}

void    Tile::setBomb(Device &device, Character *player)
{
    if (_bomb == nullptr) {
        _bomb = new Bomb(device, _pos);
        player->setBomb(true);
    }
}

void    Tile::destroyFloor()
{
    if (_floor != nullptr) {
        _floor->destroy();
        _floor = nullptr;
    }
    if (_fire != nullptr) {
        _fire->remove();
        _fire = nullptr;
    }
}

bool    Tile::checkBomb(Device &device, Character *player) {
    int impact = false;

    if (_bomb != nullptr) {
        if (_bomb->explode(device)) {
            _bomb = nullptr;
            impact = true;
        }
    }
    if (impact == true) {
        player->setBomb(false);
        if (_above != nullptr)
            _above->destroyCrate(device, player);
        if (_under != nullptr)
            _under->destroyCrate(device, player);
        if (_right != nullptr)
            _right->destroyCrate(device, player);
        if (_left != nullptr)
            _left->destroyCrate(device, player);
        _fire = new Fire(device, _pos);
        return (true);
    }
    if (_fire != nullptr && _fire->get_ttd() < device.getTime()) {
        if (_fire->remove() == true)
            _fire = nullptr;
    }
    return (false);
}

void    Tile::destroyCube()
{
    if (_model != nullptr) {
        _model->destroy();
        _model = nullptr;
    }
}

Tile::~Tile()
{
}
