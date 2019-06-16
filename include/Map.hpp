/*
** EPITECH PROJECT, 2019
** bomber_map
** File description:
** Map
*/

#ifndef MAP_HPP_
    #define MAP_HPP_

#include <iostream>
#include <vector>
#include "Tile.hpp"
#include "Device.hpp"

class Map {
	public:
		Map(Device &, irr::scene::IAnimatedMeshSceneNode *);
		~Map();
		void	randomizeMap();
        void    generateWalls(Device &);
		void	generateMap(Device &);
        void    linkTiles();
		void	displayMapWallsConsole();
		void	displayMapCratesConsole();
		void	displayMapConsole();
        void    load(Device &, irr::scene::IAnimatedMeshSceneNode *);
		bool	setCubeColision(Device &device, irr::scene::IAnimatedMeshSceneNode *player);
        bool    checkBomb(Device &, const std::vector<bool> &, Character *);
        Tile    *findTile(const irr::core::vector3df &);
        void    loadFloor(Device &);
        void    destroy();

	protected:
	private:
		std::vector<Tile *> _tiles;
        std::vector<Tile *> _walls;
};

#endif /* !MAP_HPP_ */
