/*
 * orc.h
 * CS246 Assignment 5 (CC3k)
 * Chaewoon Park (c39park) & Anusan Sivakumaran (a26sivak)
 */

#ifndef __ORC_H__
#define __ORC_H__
#include <string>
#include "enemy.h"

//Orc Class
class Orc: public Enemy
{
	private:
        //Constants used for Initlization
		static const int MAX_HP;
		static const int START_ATK;
		static const int START_DEF;
	public:
    	Orc(int r, int c);
    	~Orc();
        //Methods
    	std::string getType();
        //Visitor Pattern Methods (Combat)
		void hit(Player &p);
		void getHit(Shade &s);
		void getHit(Drow &d);
		void getHit(Vampire &v);
		void getHit(Troll &t);
		void getHit(Goblin &g);
};

#endif
