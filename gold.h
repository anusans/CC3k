/*
 * gold.h
 * CS246 Assignment 5 (CC3k)
 * Chaewoon Park (c39park) & Anusan Sivakumaran (a26sivak)
 */

#ifndef __GOLD_H__
#define __GOLD_H__
#include "entity.h"
#include "dragon.h"
#include <string>

//Gold class
class Gold: public Entity
{
  private:
    int val;
	bool canPickup; //used in coordination with dragon, (Dragon gold hoards)
	Dragon *owner; //points to the dragon that is protecting the gold hoard
  public:
    Gold(int r, int c, int val);
    ~Gold();
    //Methods
    int getVal();
	bool pickupAble();
	void allowPickup();
	std::string getType();
	Dragon *getOwner();
	void setOwner(Dragon *owner);
};

#endif
