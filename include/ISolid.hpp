/*
** EPITECH PROJECT, 2019
** OOP_indie_studio_2018
** File description:
** ISolid
*/

#ifndef ISOLID_HPP_
#define ISOLID_HPP_

#include <irrlicht.h>
#include "Device.hpp"

class ISolid {
	public:
		virtual ~ISolid() = default;

        virtual irr::scene::ISceneNode *getSceneNode() const = 0;
        virtual void setPosition(irr::core::vector3df) = 0;
        virtual void setPosition(const float &, const float &, const float &) = 0;
        virtual void setTexture(irr::video::IVideoDriver *, const std::string &) = 0;
        virtual irr::core::vector3df getPosition() const = 0;
        virtual void    walk(Device &) = 0;
        virtual void    rotate(Device &, const std::string &, const int &, const float &) = 0;
        virtual void breakIt() = 0;
        virtual bool isBroken() const = 0;
        virtual bool isDestroyable() const = 0;
        virtual void destroy() = 0;

	protected:
        bool _isBroken;
        bool _isDestroyable;
	private:
};

#endif /* !ISOLID_HPP_ */
