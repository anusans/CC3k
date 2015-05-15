/*
 * map.h
 * CS246 Assignment 5 (CC3k)
 * Chaewoon Park (c39park) & Anusan Sivakumaran (a26sivak)
 */
#ifndef __MAP_H__
#define __MAP_H__
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include "player.h"
#include "cell.h"
#include "enemy.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "halfling.h"
#include "dragon.h"
#include "potion.h"
#include "gold.h"

//Map Class
class Map {
	public:
		Cell ***floorMap; //2D array of Cells (used to make the Map)
		Cell ***room; //2D of all floor tiles (used in spawning at beginning of game)
		Map();
		~Map();
        //Methods
		void createMap();
		void printMap();
		void spawn(Entity *e, int r, int c);
		void spawn(Entity *e, Cell *c);
		void randSpawn(Entity *e);
		void despawn(int r, int c);
		bool hasOccupant(int r, int c);
		Entity *getOccupant(int r, int c);
		void setOccupant(int r, int c, Entity *e);
		void generate(Player *thePlayer);
};

#endif
