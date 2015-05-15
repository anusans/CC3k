/*
 * goblin.h
 * CS246 Assignment 5 (CC3k)
 * Chaewoon Park (c39park) & Anusan Sivakumaran (a26sivak)
 */

#ifndef __GOBLIN_H__
#define __GOBLIN_H__

#include "player.h"
#include "enemy.h"
#include <string>

//Goblin Race (.h)
class Goblin: public Player
{
	private:
        //Constant Fields (used for initilization)
		static const int MAX_HP;
		static const int START_ATK;
		static const int START_DEF;
	public:
		Goblin(int r, int c);
		~Goblin();
		std::string getType();
        //Combat Methods (Visitor Pattern)
		void hit(Enemy &e);
		void getHit(Human &h);
		void getHit(Dwarf &d);
		void getHit(Elf &e);
		void getHit(Orc &o);
		void getHit(Merchant &m);
		void getHit(Dragon &d);
		void getHit(Halfling &d);
};

#endif
