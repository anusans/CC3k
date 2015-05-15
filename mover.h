/*
 * mover.h
 * CS246 Assignment 5 (CC3k)
 * Chaewoon Park (c39park) & Anusan Sivakumaran (a26sivak)
 */
#ifndef __MOVER_H__
#define __MOVER_H__
#include <cstdlib>
#include "map.h"
#include "enemy.h"
#include "player.h"

//Mover class
class Mover {
	public:
        //Methods
		static bool shift(int r, int c, Player *p, Map *m); //move the Player
		static bool shift(int r, int c, Enemy *e, Map *m); //move an Enemy
		static void randShift(Enemy *e, Map *m); //randomized movement of Enemies
};

#endif
