/*
** EPITECH PROJECT, 2019
** bomber_map
** File description:
** Tile
*/

#ifndef TILE_HPP_
    #define TILE_HPP_
	
#include <iostream>
#include <string>
#include "Cube.hpp"
#include "Bomb.hpp"
#include "Fire.hpp"

class Tile {
	public:
		Tile(Device &, const vector3df &, const bool &, const bool &);
		~Tile();
		bool	getIsSolid() const { return (_isSolid); };
		bool	getHasCrate() const { return (_hasCrate); };
		Cube	*getCube() { return (_model); };
        vector3df   getPos() { return (_pos); };
        void    setFloor(Device &device);
        void    setBomb(Device &device, Character *player);
        bool    checkBomb(Device &device, Character *player);

		void	setCoordinates(int x, int y);
		void	setLink(Tile *link, Tile *tile);
		void	destroyCrate(Device &, Character *);
        void    destroyFloor();
        void    destroyCube();
		void	setCrate(bool);
        void    updateTiles(Device &);

        void    setAbove(Tile *tile) { _above = tile; };
        void    setUnder(Tile *tile) { _under = tile; };
        void    setRight(Tile *tile) { _right = tile; };
        void    setLeft(Tile *tile) { _left = tile; };

		Tile	*getAbove() { return (_above); };
		Tile	*getUnder() { return (_under); };
		Tile	*getRight() { return (_right); };
		Tile	*getLeft() { return (_left); };

	protected:
	private:
        Cube    *_model;
        Cube    *_floor;
		Fire	*_fire;
        Bomb    *_bomb = nullptr;
        bool    _isSolid;
		bool	_hasCrate;
		std::string	_texture;
		Tile	*_above;
		Tile	*_under;
		Tile	*_right;
		Tile	*_left;
        irr::core::vector3df _pos;
};

#endif /* !TILE_HPP_ */
