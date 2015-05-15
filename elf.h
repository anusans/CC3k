/*
 * elf.h
 * CS246 Assignment 5 (CC3k)
 * Chaewoon Park (c39park) & Anusan Sivakumaran (a26sivak)
 */

#ifndef __CS246_Final__elf__
#define __CS246_Final__elf__
#include <string>
#include "enemy.h"

//Elf Class
class Elf: public Enemy
{
	private:
        //Constants used for Initlization
		static const int MAX_HP;
		static const int START_ATK;
		static const int START_DEF;
	public:
    	Elf(int r, int c);
    	~Elf();
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
