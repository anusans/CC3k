/*
 * potion.h
 * CS246 Assignment 5 (CC3k)
 * Chaewoon Park (c39park) & Anusan Sivakumaran (a26sivak)
 */

#ifndef __POTION_H__
#define __POTION_H__
#include "entity.h"
#include "player.h"
#include "drow.h"
#include <string>

class Potion: public Entity
{
  private:
    //Potion Stat fields
    int hp;
    int atk;
    int def;
    std::string potType;
  public:
    Potion(int r, int c, std::string potType);
    ~Potion();
    //Methods
    int getHP();
    int getAtk();
    int getDef();
    std::string getType();
	std::string getPotType();
	void usePotion(Drow *d); //Drow uses a potion
	void usePotion(Player * p); //Player uses a potion
};

#endif
