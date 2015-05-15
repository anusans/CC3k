/*
 * dragon.h
 * CS246 Assignment 5 (CC3k)
 * Chaewoon Park (c39park) & Anusan Sivakumaran (a26sivak)
 */

#ifndef __DRAGON_H__
#define __DRAGON_H__
#include <string>
#include "enemy.h"
class Gold;

class Dragon: public Enemy
{
	private:
		//Constant stat values
		static const int MAX_HP;
		static const int START_ATK;
		static const int START_DEF;
		Gold *myGold; //Pointer to hoard
	public:
		//Constructor and Destructor
    	Dragon(int r, int c, Gold *myGold);
    	~Dragon();

		//Methods
		void releaseGold(); //Allows pickup of hoard
		void hit(Player &p); //attack player
		//get hit by player
		void getHit(Shade &s);
		void getHit(Drow &d);
		void getHit(Vampire &v);
		void getHit(Troll &t);
		void getHit(Goblin &g);

		//Getter
    	std::string getType();
};

#endif
