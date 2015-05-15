/*
 * troll.cc
 * CS246 Assignment 5 (CC3k)
 * Chaewoon Park (c39park) & Anusan Sivakumaran (a26sivak)
 */

#include "troll.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "dragon.h"
#include "halfling.h"
using namespace std;

//Constants
const int Troll::MAX_HP = 120;
const int Troll::START_ATK = 25;
const int Troll::START_DEF = 15;

//Constructor
Troll::Troll(int r, int c):
        Player(r,c,MAX_HP,START_ATK,START_DEF) { }

//Destructor
Troll::~Troll() {}

//Methods
std::string Troll::getType() {
	return "Troll"; //return the race of Player
}

void Troll::hit(Enemy &e) {
	e.getHit(*this); //call the getHit() method of Player
}

void Troll::getHit(Human &h) {
    //50% chance Enemy misses
	if (rand()%2 == 1) {
		int damage = ceil((100.0/(100.0+(double)getDef()))*(double)h.getAtk()); //damage calculation
		setHP(getHP() - damage); //set the HP value of Player
	}
}

void Troll::getHit(Dwarf &d) {
	if (rand()%2 == 1) {
        //50% chance Enemy misses
		int damage = ceil((100.0/(100.0+(double)getDef()))*(double)d.getAtk()); //damage calculation
		setHP(getHP() - damage); //set the HP value of Player
	}
}

void Troll::getHit(Elf &e) {
    //Elves attack twice
	for (int i=0; i<2; i++) {
        //50% chance Enemy misses
		if (rand()%2 == 1) {
			int damage = ceil((100.0/(100.0+(double)getDef()))*(double)e.getAtk()); //damage calculation
			setHP(getHP() - damage); //set the HP value of Player
		}
	}
}

void Troll::getHit(Orc &o) {
	if (rand()%2 == 1) {
        //50% chance Enemy misses
		int damage = ceil((100.0/(100.0+(double)getDef()))*(double)o.getAtk()); //damage calculation
		setHP(getHP() - damage); //set the HP value of Player
	}
}

void Troll::getHit(Merchant &m) {
	if (rand()%2 == 1) {
        //50% chance Enemy misses
		int damage = ceil((100.0/(100.0+(double)getDef()))*(double)m.getAtk()); //damage calculation
		setHP(getHP() - damage); //set the HP value of Player
	}
}

void Troll::getHit(Dragon &d) {
	if (rand()%2 == 1) {
        //50% chance Enemy misses
		int damage = ceil((100.0/(100.0+(double)getDef()))*(double)d.getAtk()); //damage calculation
		setHP(getHP() - damage); //set the HP value of Player
	}
}

void Troll::getHit(Halfling &h) {
	if (rand()%2 == 1) {
        //50% chance Enemy misses
		int damage = ceil((100.0/(100.0+(double)getDef()))*(double)h.getAtk()); //damage calculation
		setHP(getHP() - damage); //set the HP value of Player
	}
}

//Restores 5 HP to Troll (every turn)
void Troll::regen() {
	setHP(getHP()+5);
    //If HP comes to more than Troll's max Health, reset to max Health
	if (getHP() > MAX_HP) {
		setHP(MAX_HP);
	}
}
