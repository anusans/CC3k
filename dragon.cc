/*
 * dragon.cc
 * CS246 Assignment 5 (CC3k)
 * Chaewoon Park (c39park) & Anusan Sivakumaran (a26sivak)
 */

#include "dragon.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "gold.h"
using namespace std;

//Constants
const int Dragon::MAX_HP = 150;
const int Dragon::START_ATK = 20;
const int Dragon::START_DEF = 20;

//Constructor
Dragon::Dragon(int r, int c, Gold *myGold):
	Enemy(r,c,MAX_HP,START_ATK,START_DEF), myGold(myGold) { }

//Destructor
Dragon::~Dragon() {}

//Methods
string Dragon::getType() {
	return "Dragon";
}

void Dragon::releaseGold() {
	myGold->allowPickup();
}

void Dragon::hit(Player &p) {
	p.getHit(*this);
}

void Dragon::getHit(Shade &s) {
	int damage = ceil((100.0/(100.0+(double)getDef()))*(double)s.getAtk());
	setHP(getHP() - damage);
}

void Dragon::getHit(Drow &d) {
	int damage = ceil((100.0/(100.0+(double)getDef()))*(double)d.getAtk());
	setHP(getHP() - damage);
}

void Dragon::getHit(Vampire &v) {
	int damage = ceil((100.0/(100.0+(double)getDef()))*(double)v.getAtk());
	setHP(getHP() - damage);
	v.setHP(v.getHP() + 5); //vampire ability
}

void Dragon::getHit(Troll &t) {
	int damage = ceil((100.0/(100.0+(double)getDef()))*(double)t.getAtk());
	setHP(getHP() - damage);
}

void Dragon::getHit(Goblin &g) {
	int damage = ceil((100.0/(100.0+(double)getDef()))*(double)g.getAtk());
	setHP(getHP() - damage);
	if (getHP() <= 0) {
		g.addGold(5); //Goblin ability
	}
}
