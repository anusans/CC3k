//
//  human.cpp
//  CS246 Final
//
//  Created by Anusan on 2014-11-24.
//  Copyright (c) 2014 Anusan. All rights reserved.
//

#include "human.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include <string>
#include <iostream>

using namespace std;

//Constants
const int Human::MAX_HP = 140;
const int Human::START_ATK = 20;
const int Human::START_DEF = 20;

//Constructor
Human::Human(int r, int c):
	Enemy(r,c,MAX_HP,START_ATK,START_DEF) { }

//Destructor
Human::~Human() {}

//Methods
std::string Human::getType() {
	return "Human";
}

void Human::hit(Player &p) {
	p.getHit(*this);
}

void Human::getHit(Shade &s) {
	int damage = ceil((100.0/(100.0+(double)getDef()))*(double)s.getAtk());
	setHP(getHP() - damage);
	cout << damage << " damage from Shade to Human!" << endl;
	cout << "Human HP: " << getHP() << endl;
}

void Human::getHit(Drow &d) {
	int damage = ceil((100.0/(100.0+(double)getDef()))*(double)d.getAtk());
	setHP(getHP() - damage);
	cout << damage << " damage from Drow to Human!" << endl;
	cout << "Human HP: " << getHP() << endl;
}

void Human::getHit(Vampire &v) {
	int damage = ceil((100.0/(100.0+(double)getDef()))*(double)v.getAtk());
	setHP(getHP() - damage);
	v.setHP(v.getHP() + 5);
	cout << damage << " damage from Vampire to Human!" << endl;
	cout << "Human HP: " << getHP() << endl;
}

void Human::getHit(Troll &t) {
	int damage = ceil((100.0/(100.0+(double)getDef()))*(double)t.getAtk());
	setHP(getHP() - damage);
	cout << damage << " damage from Troll to Human!" << endl;
	cout << "Human HP: " << getHP() << endl;
}

void Human::getHit(Goblin &g) {
	int damage = ceil((100.0/(100.0+(double)getDef()))*(double)g.getAtk());
	setHP(getHP() - damage);
	if (getHP() <= 0) {
		g.addGold(5);
	}
	cout << damage << " damage from Goblin to Human!" << endl;
	cout << "Human HP: " << getHP() << endl;
}
