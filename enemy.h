/*
 * enemy.h
 * CS246 Assignment 5 (CC3k)
 * Chaewoon Park (c39park) & Anusan Sivakumaran (a26sivak)
 */

#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "character.h"
//Forward Declations
class Player;
class Shade;
class Drow;
class Vampire;
class Troll;
class Goblin;
#include <string>
#include <iostream>

//Abstract Class
class Enemy: public Character
{
  public:
    Enemy(int r, int c, int hp, int atk, int def);
    ~Enemy();
	
    //Pure Virtual Methods
    virtual void hit(Player &p) = 0;
    virtual void getHit(Shade &s) = 0;
    virtual void getHit(Drow &d) = 0;
    virtual void getHit(Vampire &v) = 0;
    virtual void getHit(Troll &t) = 0;
    virtual void getHit(Goblin &t) = 0;

};

#endif
