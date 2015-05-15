/*
 * drow.h
 * CS246 Assignment 5 (CC3k)
 * Chaewoon Park (c39park) & Anusan Sivakumaran (a26sivak)
 */

#ifndef __DROW_H__
#define __DROW_H__

#include "player.h"
#include <string>

class Drow: public Player
{
	private:
        //Constant used for Initlization
		static const int MAX_HP;
		static const int START_ATK;
		static const int START_DEF;
	public:
		Drow(int r, int c);
		~Drow();
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
};

#endif
