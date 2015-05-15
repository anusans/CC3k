//
//  halfling.cpp
//  CS246 Final
//
//  Created by Anusan on 2014-11-24.
//  Copyright (c) 2014 Anusan. All rights reserved.
//

#include "halfling.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include <cstdlib>
using namespace std;

//Constants
const int Halfling::MAX_HP = 100;
const int Halfling::START_ATK = 15;
const int Halfling::START_DEF = 20;

//Constructor
Halfling::Halfling(int r, int c):
	Enemy(r,c,MAX_HP,START_ATK,START_DEF) { }

//Destructor
Halfling::~Halfling() {}

//Methods
string Halfling::getType() {
	return "Halfling";
}

void Halfling::hit(Player &p) {
	p.getHit(*this);
}

void Halfling::getHit(Shade &s) {
	if (rand()%2 == 1) {
		int damage = ceil((100.0/(100.0+(double)getDef()))*(double)s.getAtk());
		setHP(getHP() - damage);
		cout << damage << " damage from Shade to Halfling!" << endl;
		cout << "Halfling HP: " << getHP() << endl;
	} else {cout << "Missed!" << endl;}
}

void Halfling::getHit(Drow &d) {
	if (rand()%2 == 1) {
		int damage = ceil((100.0/(100.0+(double)getDef()))*(double)d.getAtk());
		setHP(getHP() - damage);
		cout << damage << " damage from Shade to Halfling!" << endl;
		cout << "Halfling HP: " << getHP() << endl;
	} else {cout << "Missed!" << endl;}
}

void Halfling::getHit(Vampire &v) {
	if (rand()%2 == 1) {
		int damage = ceil((100.0/(100.0+(double)getDef()))*(double)v.getAtk());
		setHP(getHP() - damage);
		v.setHP(v.getHP() + 5);
		cout << damage << " damage from Vampire to Halfling!" << endl;
		cout << "Halfling HP: " << getHP() << endl;
	} else {cout << "Missed!" << endl;}
}

void Halfling::getHit(Troll &t) {
	if (rand()%2 == 1) {
		int damage = ceil((100.0/(100.0+(double)getDef()))*(double)t.getAtk());
		setHP(getHP() - damage);
		cout << damage << " damage from Shade to Halfling!" << endl;
		cout << "Halfling HP: " << getHP() << endl;
	} else {cout << "Missed!" << endl;}
}

void Halfling::getHit(Goblin &g) {
	if (rand()%2 == 1) {
		int damage = ceil((100.0/(100.0+(double)getDef()))*(double)g.getAtk());
		setHP(getHP() - damage);
		if (getHP() <= 0) {
			g.addGold(5);
		}
		cout << damage << " damage from Goblin to Halfling!" << endl;
		cout << "Halfling HP: " << getHP() << endl;
	} else {cout << "Missed!" << endl;}
}
