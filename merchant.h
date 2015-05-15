/*
 * merchant.h
 * CS246 Assignment 5 (CC3k)
 * Chaewoon Park (c39park) & Anusan Sivakumaran (a26sivak)
 */

#ifndef __MERCHANT_H__
#define __MERCHANT_H__
#include <string>
#include "enemy.h"

//Merchant class
class Merchant: public Enemy
{
	private:
        //Constants used for Initialization
		static const int MAX_HP;
		static const int START_ATK;
		static const int START_DEF;
	public:
    	Merchant(int r, int c);
    	~Merchant();
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