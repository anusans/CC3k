/*
 * status.h
 * CS246 Assignment 5 (CC3k)
 * Chaewoon Park (c39park) & Anusan Sivakumaran (a26sivak)
 */

#ifndef __STATUS_H__
#define __STATUS_H__
#include "map.h"
#include "entity.h"
#include "player.h"
#include "enemy.h"

class Status {
	private:
		Map *theMap;
		Player *thePlayer;
	public:
		//Constructor and Destructor
		Status(Map *m, Player *p);
		~Status();

		//Checks for deaths (<=0 HP), moves enemies
		void update();
};

#endif
