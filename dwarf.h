/*
 * dwarf.h
 * CS246 Assignment 5 (CC3k)
 * Chaewoon Park (c39park) & Anusan Sivakumaran (a26sivak)
 */

#ifndef __CS246_Final__dwarf__
#define __CS246_Final__dwarf__
#include <string>
#include "enemy.h"
#include "shade.h"

//Dwarf Class
class Dwarf: public Enemy
{
	private:
        //Constants used for Initialization
		static const int MAX_HP;
		static const int START_ATK;
		static const int START_DEF;
	public:
    	Dwarf(int r, int c);
    	~Dwarf();
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
