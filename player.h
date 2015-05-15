/*
 * player.h
 * CS246 Assignment 5 (CC3k)
 * Chaewoon Park (c39park) & Anusan Sivakumaran (a26sivak)
 */

#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "character.h"
class Enemy;
class Human;
class Dwarf;
class Elf;
class Orc;
class Merchant;
class Dragon;
class Halfling;

class Player: public Character
{
  private:
    int wallet;
  public:
    Player(int r, int c, int hp, int atk, int def);
    ~Player();
    void addGold(int val);
	int getGold();
    virtual void hit(Enemy &e) = 0;
	virtual void getHit(Human &h) = 0;
	virtual void getHit(Dwarf &d) = 0;
	virtual void getHit(Elf &e) = 0;
	virtual void getHit(Orc &o) = 0;
	virtual void getHit(Merchant &m) = 0;
	virtual void getHit(Dragon &d) = 0;
	virtual void getHit(Halfling &h) = 0;
};

#endif
