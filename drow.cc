/*
 * drow.cc
 * CS246 Assignment 5 (CC3k)
 * Chaewoon Park (c39park) & Anusan Sivakumaran (a26sivak)
 */

#include "drow.h"
#include "enemy.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "dragon.h"
#include "halfling.h"
using namespace std;

//Constants (used for Initilization)
const int Drow::MAX_HP = 150;
const int Drow::START_ATK = 25;
const int Drow::START_DEF = 15;

//Constructor
Drow::Drow(int r, int c): Player(r,c,MAX_HP,START_ATK,START_DEF) { }

//Destructor
Drow::~Drow() { }

//Methods

std::string Drow::getType() {
	return "Drow"; //return the race of Player
}

void Drow::hit(Enemy &e) {
	e.getHit(*this); //call the getHit() method of Enemy
}

void Drow::getHit(Human &h) {
	if (rand()%2 == 1) {
        //50% chance Enemy misses
		int damage = ceil((100.0/(100.0+(double)getDef()))*(double)h.getAtk()); //damage calculation
		setHP(getHP() - damage); //set HP value of Player
	}
}

void Drow::getHit(Dwarf &d) {
	if (rand()%2 == 1) {
        //50% chance Enemy misses
		int damage = ceil((100.0/(100.0+(double)getDef()))*(double)d.getAtk()); //damage calculation
		setHP(getHP() - damage); //set HP value of Player
	}
}

void Drow::getHit(Elf &e) {	
	if (rand()%2 == 1) {
        //50% chance Enemy misses
		int damage = ceil((100.0/(100.0+(double)getDef()))*(double)e.getAtk()); //damage calculation
		setHP(getHP() - damage); //set HP value of Player
	}
}

void Drow::getHit(Orc &o) {
	if (rand()%2 == 1) {
        //50% chance Enemy misses
		int damage = ceil((100.0/(100.0+(double)getDef()))*(double)o.getAtk()); //damage calculation
		setHP(getHP() - damage); //set HP value of Player
	}
}

void Drow::getHit(Merchant &m) {
	if (rand()%2 == 1) {
        //50% chance Enemy misses
		int damage = ceil((100.0/(100.0+(double)getDef()))*(double)m.getAtk()); //damage calculation
		setHP(getHP() - damage); //set HP value of Player
	}
}

void Drow::getHit(Dragon &d) {
	if (rand()%2 == 1) {
        //50% chance Enemy misses
		int damage = ceil((100.0/(100.0+(double)getDef()))*(double)d.getAtk()); //damage calculation
		setHP(getHP() - damage); //set HP value of Player
	}
}

void Drow::getHit(Halfling &h) {
	if (rand()%2 == 1) {
		int damage = ceil((100.0/(100.0+(double)getDef()))*(double)h.getAtk()); //damage calculation
		setHP(getHP() - damage); //set HP value of Player
	}
}
