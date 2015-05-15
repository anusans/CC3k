/*
 * orc.cc
 * CS246 Assignment 5 (CC3k)
 * Chaewoon Park (c39park) & Anusan Sivakumaran (a26sivak)
 */

#include "orc.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
using namespace std;

//Constants (used for Initilization)
const int Orc::MAX_HP = 180;
const int Orc::START_ATK = 30;
const int Orc::START_DEF = 25;

//Constructor
Orc::Orc(int r, int c): Enemy(r,c,MAX_HP,START_ATK,START_DEF) { }

//Destructor
Orc::~Orc() {}

//Methods
string Orc::getType() {
	return "Orc"; //return the race of Enemy
}

void Orc::hit(Player &p) {
	p.getHit(*this); //call the getHit() method of Player
}

void Orc::getHit(Shade &s) {
	int damage = ceil((100.0/(100.0+(double)getDef()))*(double)s.getAtk()); //damage calculation
	setHP(getHP() - damage); //set the HP value of Player
}

void Orc::getHit(Drow &d) {
	int damage = ceil((100.0/(100.0+(double)getDef()))*(double)d.getAtk()); //damage calculation
	setHP(getHP() - damage); //set the HP value of Player
}

void Orc::getHit(Vampire &v) {
	int damage = ceil((100.0/(100.0+(double)getDef()))*(double)v.getAtk()); //damage calculation
	setHP(getHP() - damage); //set the HP value of Player
	v.setHP(v.getHP() + 5); //Vampire regenerates 5 HP every turn
}

void Orc::getHit(Troll &t) {
	int damage = ceil((100.0/(100.0+(double)getDef()))*(double)t.getAtk()); //damage calculation
	setHP(getHP() - damage); //set the HP value of Player
}

void Orc::getHit(Goblin &g) {
	int damage = ceil((100.0/(100.0+(double)getDef()))*(double)g.getAtk()); //damage calculation
	setHP(getHP() - damage); //set the HP value of Player
	if (getHP() <= 0) {
		g.addGold(5); //Goblin steals 5 gold from slain Enemies
	}
}
