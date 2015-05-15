/*
 * goblin.cc
 * CS246 Assignment 5 (CC3k)
 * Chaewoon Park (c39park) & Anusan Sivakumaran (a26sivak)
 */

#include "goblin.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "dragon.h"
#include "halfling.h"
using namespace std;

//Constants (used for Initialization)
const int Goblin::MAX_HP = 110;
const int Goblin::START_ATK = 15;
const int Goblin::START_DEF = 20;

//Constructor
Goblin::Goblin(int r, int c): Player(r,c,MAX_HP,START_ATK,START_DEF) { }

//Destructor
Goblin::~Goblin() { }

//Methods
std::string Goblin::getType() {
	return "Goblin"; //returns the race name of Player (Goblin in this case)
}

void Goblin::hit(Enemy &e) {
	e.getHit(*this); //Visitor Pattern -> call the getHit() method of that enemy
}

void Goblin::getHit(Human &h) {
    //50% chance enemy misses
	if (rand()%2 == 1) {
		int damage = ceil((100.0/(100.0+(double)getDef()))*(double)h.getAtk()); //damage calculation
		setHP(getHP() - damage); //set the new HP value for Player
	}
}

void Goblin::getHit(Dwarf &d) {
    //50% chance enemy misses
	if (rand()%2 == 1) {
		int damage = ceil((100.0/(100.0+(double)getDef()))*(double)d.getAtk()); //damage calculation
		setHP(getHP() - damage); //set the new HP value for Player
	}
}

void Goblin::getHit(Elf &e) {
    //Recieve double damage from Elves
	for (int i=0; i<2; i++) {
        //50% chance enemy misses
		if (rand()%2 == 1) {
			int damage = ceil((100.0/(100.0+(double)getDef()))*(double)e.getAtk()); //damage calculation
			setHP(getHP() - damage); //set the new HP value for Player
		}
	}
}

void Goblin::getHit(Orc &o) {
    //50% chance enemy misses
	if (rand()%2 == 1) {
		int damage = ceil((100.0/(100.0+(double)getDef()))*(double)o.getAtk()); //damage calculation
		damage *= 1.5; //Orcs deal 50% more damage to Goblins
		setHP(getHP() - damage); //set the new HP value for Player
	}
}

void Goblin::getHit(Merchant &m) {
    //50% cgance enemy misses
	if (rand()%2 == 1) {
		int damage = ceil((100.0/(100.0+(double)getDef()))*(double)m.getAtk()); //damage calculation
		setHP(getHP() - damage); //set the new HP value for Player
	}
}

void Goblin::getHit(Dragon &d) {
    //50% chance enemy misses
	if (rand()%2 == 1) {
		int damage = ceil((100.0/(100.0+(double)getDef()))*(double)d.getAtk()); //damage calculation
		setHP(getHP() - damage); //set the new HP value for Player
	}
}

void Goblin::getHit(Halfling &h) {
    //50% chance enemy misses
	if (rand()%2 == 1) {
		int damage = ceil((100.0/(100.0+(double)getDef()))*(double)h.getAtk()); //damage calculation
		setHP(getHP() - damage); //set the new HP value for Player
	}
}
