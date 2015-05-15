/*
 * vampire.cc
 * CS246 Assignment 5 (CC3k)
 * Chaewoon Park (c39park) & Anusan Sivakumaran (a26sivak)
 */

#include "vampire.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "dragon.h"
#include "halfling.h"
#include <string>
using namespace std;

//Constants (used for Initialization)
const int Vampire::START_HP = 50;
const int Vampire::START_ATK = 25;
const int Vampire::START_DEF = 25;

//Constructor
Vampire::Vampire(int r, int c): Player(r,c,START_HP,START_ATK,START_DEF) { }

//Destructor
Vampire::~Vampire() { }

//Methods
std::string Vampire::getType() {
	return "Vampire"; //return the race of Player
}

void Vampire::hit(Enemy &e) {
	e.getHit(*this); //call the getHit() method of Enemy
}

void Vampire::getHit(Human &h) {
	if (rand()%2 == 1) {
        //50% chance Enemy misses
		int damage = ceil((100.0/(100.0+(double)getDef()))*(double)h.getAtk()); //damage calculation
		setHP(getHP() - damage); //set the HP value of Player
	}
}

void Vampire::getHit(Dwarf &d) {
	if (rand()%2 == 1) {
        //50% chance Enemy misses
		int damage = ceil((100.0/(100.0+(double)getDef()))*(double)d.getAtk()); //damage calculation
		setHP(getHP() - damage); //set the HP value of Player
	}
}

void Vampire::getHit(Elf &e) {
    //Elves get 2 attacks
	for (int i=0; i<2; i++) {	
		if (rand()%2 == 1) {
            //50% chance Enemy misses
			int damage = ceil((100.0/(100.0+(double)getDef()))*(double)e.getAtk()); //damage calculation
			setHP(getHP() - damage); //set the HP value of Player
		}
	}
}

void Vampire::getHit(Orc &o) {
	if (rand()%2 == 1) {
        //50% chance Enemy misses
		int damage = ceil((100.0/(100.0+(double)getDef()))*(double)o.getAtk()); //damage calculation
		setHP(getHP() - damage); //set the HP value of Player
	}
}

void Vampire::getHit(Merchant &m) {
	if (rand()%2 == 1) {
        //50% chance Enemy misses
		int damage = ceil((100.0/(100.0+(double)getDef()))*(double)m.getAtk()); //damage calculation
		setHP(getHP() - damage); //set the HP value of Player
	}
}

void Vampire::getHit(Dragon &d) {
	if (rand()%2 == 1) {
        //50% chance Enemy misses
		int damage = ceil((100.0/(100.0+(double)getDef()))*(double)d.getAtk()); //damage calculation
		setHP(getHP() - damage); //set the HP value of Player
	}
}

void Vampire::getHit(Halfling &h) {
	if (rand()%2 == 1) {
        //50% chance Enemy misses
		int damage = ceil((100.0/(100.0+(double)getDef()))*(double)h.getAtk()); //damage calculation
		setHP(getHP() - damage); //set the HP value of Player
	}
}
