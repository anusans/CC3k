/*
 * drow.cc
 * CS246 Assignment 5 (CC3k)
 * Chaewoon Park (c39park) & Anusan Sivakumaran (a26sivak)
 */

#include "dwarf.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
using namespace std;

//Constants
const int Dwarf::MAX_HP = 100;
const int Dwarf::START_ATK = 20;
const int Dwarf::START_DEF = 30;

//Constructor
Dwarf::Dwarf(int r, int c):
	Enemy(r,c,MAX_HP,START_ATK,START_DEF) { }

//Destructor
Dwarf::~Dwarf() {}

//Methods
string Dwarf::getType() {
	return "Dwarf"; //return the type of Enemy
}

void Dwarf::hit(Player &p) {
	p.getHit(*this); //call the getHit() method of Player
}

void Dwarf::getHit(Shade &s) {
	int damage = ceil((100.0/(100.0+(double)getDef()))*(double)s.getAtk()); //damage calculation
	setHP(getHP() - damage); //set the HP value of Enemy
}

void Dwarf::getHit(Drow &d) {
	int damage = ceil((100.0/(100.0+(double)getDef()))*(double)d.getAtk()); //damage calculation
	setHP(getHP() - damage); //set the HP value of Enemy
}

void Dwarf::getHit(Vampire &v) {
	int damage = ceil((100.0/(100.0+(double)getDef()))*(double)v.getAtk()); //damage calculation
	setHP(getHP() - damage); //set the HP value of Enemy
	v.setHP(v.getHP() - 5); //Vampires are allergic to Dwarves
}

void Dwarf::getHit(Troll &t) {
	int damage = ceil((100.0/(100.0+(double)getDef()))*(double)t.getAtk()); //damage calculation
	setHP(getHP() - damage); //set the HP value of Enemy
}

void Dwarf::getHit(Goblin &g) {
	int damage = ceil((100.0/(100.0+(double)getDef()))*(double)g.getAtk()); //damage calculation
	setHP(getHP() - damage); //set the HP value of Enemy
	if (getHP() <= 0) {
		g.addGold(5); //Goblins steal 5 Gold from slain Enemies
	}
}
