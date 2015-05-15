/*
 * main.cc
 * CS246 Assignment 5 (CC3k)
 * Chaewoon Park (c39park) & Anusan Sivakumaran (a26sivak)
 */

#ifndef __SHADE_H__
#define __SHADE_H__

#include "player.h"
#include "enemy.h"
#include <string>

//Shade Class
class Shade: public Player
{
	private:
        //Constants used for Initialization
		static const int MAX_HP;
		static const int START_ATK;
		static const int START_DEF;
	public:
		Shade(int r, int c);
		~Shade();
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
