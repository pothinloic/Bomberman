/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Character
*/

#include "../include/Character.hpp"

Character::Character(const std::string &pathModel, const std::string &pathTexture, Device &device)
{
    _mesh = device.getSmgr()->addAnimatedMeshSceneNode(device.getSmgr()->getMesh(pathModel.c_str()));
    _mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
    _mesh->setMaterialTexture(0, device.getDriver()->getTexture(pathTexture.c_str()));
    _mesh->setScale(irr::core::vector3df(15.0f, 15.0f, 15.0f));
    _mesh->setRotation(core::vector3df(90, 0, 0));
    _mesh->setAnimationSpeed(30);
    _pos = _mesh->getPosition();
    _mesh->setPosition(core::vector3df(0, 0, -1));
    _mesh->setFrameLoop(27, 76);
    _isDestroyable = true;
    _isBroken = false;
    _then = device.getDevice()->getTimer()->getTime();
    _isWalking = false;
    _bomb = false;
}

void Character::destroy()
{
    _mesh->remove();
}

void    Character::rotate(Device &device, const std::string &axe, const int &rotation, const float &frameDeltaTime)
{
    _mesh->setRotation(core::vector3df(90, 0, rotation));
    if (_isWalking == false) {
        _isWalking = true;
        _mesh->setFrameLoop(0, 26);
    }
    ((axe == "X") ? _pos.X : _pos.Y) += MOVEMENT_SPEED * frameDeltaTime;
    _mesh->setPosition(_pos);
}

void    Character::walk(Device &device)
{
    int now = device.getDevice()->getTimer()->getTime();
    float frameDeltaTime = (float)(now - _then) / 1000.f;
    std::vector<bool>   input = device.getKey().getVectorKey();

    _then = now;
    _pos = _mesh->getPosition();
    for (int i = 0; i != input.size(); i++) {
        if (input[i] == true)
            _inside = true;
    }
    if (input[e_action::BOMB] == true) {
    }
    if (input[e_action::UP] == true)
        rotate(device, "Y", 0, frameDeltaTime);
    if (input[e_action::DOWN] == true)
        rotate(device, "Y", 180, frameDeltaTime * -1);
    if (input[e_action::LEFT] == true)
        rotate(device, "X", 270, frameDeltaTime);
    if (input[e_action::RIGHT] == true)
        rotate(device, "X", 90, frameDeltaTime * -1);
    if (_isWalking == true && _inside == false) {
        _isWalking = false;
        _mesh->setFrameLoop(27, 76);
    }
    _inside = false;
}

void Character::setTexture(irr::video::IVideoDriver *driver, const std::string &pathTexture)
{
    _mesh->setMaterialTexture( 0, driver->getTexture(pathTexture.c_str()));
}

void Character::setPosition(irr::core::vector3df vector = irr::core::vector3df(0, 0, 0))
{
    _mesh->setPosition(vector);
}

irr::core::vector3df Character::getPosition() const 
{
    return _mesh->getAbsolutePosition();
}

void Character::setPosition(const float &x = 0, const float &y = 0, const float &z = 0)
{
    _mesh->setPosition(irr::core::vector3df(x, y, z));
}

void    Character::destroy(Device &device)
{
    _mesh->remove();
    _mesh = nullptr;
    device.setGame(false);
    device.stopMusic();
    device.playMusic("music/menuintro.ogg", false);
}

Character::~Character()
{
    delete _mesh;
}
