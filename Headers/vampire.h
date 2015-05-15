/*
 * vampire.h
 * CS246 Assignment 5 (CC3k)
 * Chaewoon Park (c39park) & Anusan Sivakumaran (a26sivak)
 */

#ifndef __VAMPIRE_H__
#define __VAMPIRE_H__

#include "player.h"
#include "enemy.h"
#include <string>

class Vampire: public Player
{
	private:
        //Constants used for Initialization
		static const int START_HP;
		static const int START_ATK;
		static const int START_DEF;
 	public:
		Vampire(int r, int c);
		~Vampire();
        //Methods
		std::string getType();
        //Visitor Patern Methods (Combat)
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
