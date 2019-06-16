/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <iostream>
#include <string>
#include "ISolid.hpp"
#include "Key.hpp"
#include "Device.hpp"

enum
{
	ID_IsNotPickable = 0,
	IDFlag_IsPickable = 1 << 0,
	IDFlag_IsHighlightable = 1 << 1
};

class Character : public ISolid {
	public:
        Character(const std::string &, const std::string &, Device &);
		~Character();

        irr::scene::IAnimatedMeshSceneNode *getSceneNode() const {return _mesh;}
        void    setPosition(irr::core::vector3df);
        void    setPosition(const float &, const float &, const float &);
        irr::core::vector3df    getPosition() const;
        void    setTexture(irr::video::IVideoDriver *, const std::string &);
        void    walk(Device &);
        void    rotate(Device &, const std::string &, const int &, const float &);
        void    breakIt() { _isBroken = true; };
        bool    isBroken() const { return _isBroken; };
        bool    isDestroyable() const {return _isDestroyable;};
        void    destroy();
		irr::scene::IAnimatedMeshSceneNode *getCharacter() const { return _mesh; };
        void    setBomb(bool bomb) { _bomb = bomb; };
        bool    hasBomb(void) { return(_bomb); };
        void    destroy(Device &);

	protected:
	private:
        int _then;
        const float MOVEMENT_SPEED = 30;
        irr::scene::IAnimatedMeshSceneNode *_mesh;
        irr::core::vector3df    _pos;
        KeyManagement _key;
        bool    _isWalking;
        bool    _inside;
        bool    _bomb;
};

#endif /* !CHARACTER_HPP_ */
