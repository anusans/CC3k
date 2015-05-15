/*
 * character.h
 * CS246 Assignment 5 (CC3k)
 * Chaewoon Park (c39park) & Anusan Sivakumaran (a26sivak)
 */

#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "entity.h"
#include <math.h>
#include <string>
#include <cstdlib>

class Character: public Entity
{
  private:
    int hp; //character hp
    int atk; //character atk
    int def; //character def
	int atkBoost; //temporary atk boost from potion
	int defBoost; //temporaroy def boost from potion
 public:
	//Constructor and Destructor
    Character(int r, int c, int hp, int atk, int def);
    ~Character();

	//Setters and Getters
    int getHP();
    int getAtk();
    int getDef();
    void setHP(int h);
    void setAtkB(int a);
    void setDefB(int d);
	int getAtkB();
	int getDefB();
};

#endif
