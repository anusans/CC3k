/*
 * character.cc
 * CS246 Assignment 5 (CC3k)
 * Chaewoon Park (c39park) & Anusan Sivakumaran (a26sivak)
 */

#include "character.h"
#include <iostream>
#include <string>
using namespace std;

//Constructor
Character::Character(int r, int c, int hp, int atk, int def): Entity(r,c), hp(hp), atk(atk), def(def) {
	atkBoost = 0;
	defBoost = 0;
}

//Destructor
Character::~Character() { }


int Character::getHP()
{
    if (hp >= 0) {
		return hp; //return the HP value of the Character
	} else {
		return 0; //HP can't be negative
	}
}

int Character::getAtk()
{
    return atk + atkBoost; //return the ATK value of the Character
}

int Character::getDef()
{
    return def + defBoost; //return the DEF value of the Character
}

void Character::setHP(int h)
{
    hp = h; //sets value of hp with h
}

void Character::setAtkB(int a)
{
    atkBoost = a; //changes value of atk with a
}

void Character::setDefB(int d)
{
    defBoost = d; //changes value of def with d
}

int Character::getAtkB() {
	return atkBoost;
}

int Character::getDefB() {
	return defBoost;
}
