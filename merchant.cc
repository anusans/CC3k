/*
 * merchant.cc
 * CS246 Assignment 5 (CC3k)
 * Chaewoon Park (c39park) & Anusan Sivakumaran (a26sivak)
 */

#include "merchant.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
using namespace std;

//Constants (used in Intiailization)
const int Merchant::MAX_HP = 30;
const int Merchant::START_ATK = 70;
const int Merchant::START_DEF = 5;

extern bool angryMerch; //bool flag - used to make the Merchant aggressive

//Constructor
Merchant::Merchant(int r, int c): Enemy(r,c,MAX_HP,START_ATK,START_DEF) { }

//Destructor
Merchant::~Merchant() {}

//Methods
string Merchant::getType() {
	return "Merchant"; //return the race of Enemy
}

void Merchant::hit(Player &p) {
	p.getHit(*this); //call the getHit() method of Player
}

void Merchant::getHit(Shade &s) {
	angryMerch = true; //set the Merchant to aggressive
	int damage = ceil((100.0/(100.0+(double)getDef()))*(double)s.getAtk()); //damage calculation
	setHP(getHP() - damage); //set the HP value of Enemy
}

void Merchant::getHit(Drow &d) {
	angryMerch = true; //set the Merchant to aggressive
	int damage = ceil((100.0/(100.0+(double)getDef()))*(double)d.getAtk()); //damage calculation
	setHP(getHP() - damage); //set the HP value of Enemy
}

void Merchant::getHit(Vampire &v) {
	angryMerch = true; //set the Merchant to aggressive
	int damage = ceil((100.0/(100.0+(double)getDef()))*(double)v.getAtk()); //damage calculation
	setHP(getHP() - damage); //set the HP value of Enemy
	v.setHP(v.getHP() + 5); //Vampire regenerates HP at end of attack
}

void Merchant::getHit(Troll &t) {
	angryMerch = true; //set the Merchant to aggressive
	int damage = ceil((100.0/(100.0+(double)getDef()))*(double)t.getAtk()); //damage calculation
	setHP(getHP() - damage); //set the HP value of Enemy
}

void Merchant::getHit(Goblin &g) {
	angryMerch = true; //set the Merchan to aggressive
	int damage = ceil((100.0/(100.0+(double)getDef()))*(double)g.getAtk()); //damage calculation
	setHP(getHP() - damage); //set the HP value of Enemy
	if (getHP() <= 0) {
		g.addGold(5); //Goblin steals 5 Gold from slain
	}
}
