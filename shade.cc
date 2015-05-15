/*
 * shade.cc
 * CS246 Assignment 5 (CC3k)
 * Chaewoon Park (c39park) & Anusan Sivakumaran (a26sivak)
 */

#include "shade.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "dragon.h"
#include "halfling.h"
using namespace std;

//Constants (used for Initilization)
const int Shade::MAX_HP = 125;
const int Shade::START_ATK = 25;
const int Shade::START_DEF = 25;

//Constructor
Shade::Shade(int r, int c): Player(r,c,MAX_HP,START_ATK,START_DEF) { }

//Destructor
Shade::~Shade() { }

//Methods
std::string Shade::getType() {
	return "Shade"; //return the race of Player
}

void Shade::hit(Enemy &e) {
	e.getHit(*this); //call the getHit() method of Enemy
}

void Shade::getHit(Human &h) {
    //50% chance Enemy misses
	if (rand()%2 == 1) {
		int damage = ceil((100.0/(100.0+(double)getDef()))*(double)h.getAtk()); //damage calculation
		setHP(getHP() - damage); //set the HP value of Player
	} else { }
}

void Shade::getHit(Dwarf &d) {
    //50% chance Enemy missed
	if (rand()%2 == 1) {
		int damage = ceil((100.0/(100.0+(double)getDef()))*(double)d.getAtk()); //damage calculation
		setHP(getHP() - damage); //set the HP value of Player
	} else { }
}

void Shade::getHit(Elf &e) {
    //Elves do double damage
	for (int i=0; i<2; i++) {	
		if (rand()%2 == 1) {
            //50% chance Enemy missed
			int damage = ceil((100.0/(100.0+(double)getDef()))*(double)e.getAtk()); //damage calculation
			setHP(getHP() - damage); //set the HP value of Player
		} else { }
	}
}

void Shade::getHit(Orc &o) {
    //50% chance Enemy missed
	if (rand()%2 == 1) {
		int damage = ceil((100.0/(100.0+(double)getDef()))*(double)o.getAtk()); //damage calculation
		setHP(getHP() - damage); //set the HP value of Player
	} else { }
}

void Shade::getHit(Merchant &m) {
    //50% chance Enemy missed
	if (rand()%2 == 1) {
		int damage = ceil((100.0/(100.0+(double)getDef()))*(double)m.getAtk()); //damage calculation
		setHP(getHP() - damage); //set the HP value of Player
	} else { }
}

void Shade::getHit(Dragon &d) {
    //50% chance Enemy missed
	if (rand()%2 == 1) {
		int damage = ceil((100.0/(100.0+(double)getDef()))*(double)d.getAtk()); //damage calculation
		setHP(getHP() - damage); //set the HP value of Player
	} else { }
}

void Shade::getHit(Halfling &h) {
    //50% chance Enemy missed
	if (rand()%2 == 1) {
		int damage = ceil((100.0/(100.0+(double)getDef()))*(double)h.getAtk()); //damage calculation
		setHP(getHP() - damage); //set the HP value of Player
	} else { }
}
