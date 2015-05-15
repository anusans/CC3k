/*
 * troll.h
 * CS246 Assignment 5 (CC3k)
 * Chaewoon Park (c39park) & Anusan Sivakumaran (a26sivak)
 */

#ifndef __TROLL_H__
#define __TROLL_H__

#include "player.h"
#include "enemy.h"
#include <string>

class Troll: public Player
{
	private:
        //Constants used for Initilization
		static const int MAX_HP;
		static const int START_ATK;
		static const int START_DEF;
	public:
		Troll(int r, int c);
		~Troll();
        //Methods
		std::string getType();
        //Visitor Pattern Methods (Combat)
		void hit(Enemy &e);
		void getHit(Human &h);
		void getHit(Dwarf &d);
		void getHit(Elf &e);
		void getHit(Orc &o);
		void getHit(Merchant &m);
		void getHit(Dragon &d);
		void getHit(Halfling &d);
		void regen();
};

#endif
