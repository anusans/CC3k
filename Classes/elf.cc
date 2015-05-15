/*
 * elf.cc
 * CS246 Assignment 5 (CC3k)
 * Chaewoon Park (c39park) & Anusan Sivakumaran (a26sivak)
 */


#include "elf.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
using namespace std;

//Constants (used for Initilzation)
const int Elf::MAX_HP = 140;
const int Elf::START_ATK = 20;
const int Elf::START_DEF = 20;

//Constructor
Elf::Elf(int r, int c): Enemy(r,c,MAX_HP,START_ATK,START_DEF) { }

//Destructor
Elf::~Elf() {}

//Methods
string Elf::getType() {
	return "Elf"; //return the race of Enemy
}

void Elf::hit(Player &p) {
	p.getHit(*this); //call the getHit() method of Player
}

void Elf::getHit(Shade &s) {
	int damage = ceil((100.0/(100.0+(double)getDef()))*(double)s.getAtk()); //damage calculation
	setHP(getHP() - damage); //set the HP value of Enemy
}

void Elf::getHit(Drow &d) {
	int damage = ceil((100.0/(100.0+(double)getDef()))*(double)d.getAtk()); //damage calculation
	setHP(getHP() - damage); //set the HP value of Enemy
}

void Elf::getHit(Vampire &v) {
	int damage = ceil((100.0/(100.0+(double)getDef()))*(double)v.getAtk()); //damage calculation
	setHP(getHP() - damage); //set the HP value of Enemy
	v.setHP(v.getHP() + 5); //Vampire regenerated 5 HP (every attack)
}

void Elf::getHit(Troll &t) {
	int damage = ceil((100.0/(100.0+(double)getDef()))*(double)t.getAtk()); //damage calculation
	setHP(getHP() - damage); //set the HP value of Enemy
}

void Elf::getHit(Goblin &g) {
	int damage = ceil((100.0/(100.0+(double)getDef()))*(double)g.getAtk()); //damage calculation
	setHP(getHP() - damage); //set the HP value of Enemy
	if (getHP() <= 0) {
		g.addGold(5); //Goblin steals 5 Gold from slain Enemy
	}
}
