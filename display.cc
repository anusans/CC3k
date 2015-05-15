/*
 * display.cc
 * CS246 Assignment 5 (CC3k)
 * Chaewoon Park (c39park) & Anusan Sivakumaran (a26sivak)
 */

#include "display.h"
using namespace std;
extern int floorNum;

Display::Display(Map *m, Player *p):
	theMap(m), thePlayer(p) {
}

void Display::update() {
	pRace = thePlayer->getType();
	gold = thePlayer->getGold();
	hp = thePlayer->getHP();
	atk = thePlayer->getAtk();
	def = thePlayer->getDef();
}

void Display::print() {
	update();
	theMap->printMap();
	cout << "Race: " << left << setw(8) << pRace;
	cout << " Gold: " << left << setw(10) << gold;
	cout << right << setw(44) << "Floor: " << floorNum << endl;
	cout << "HP: " << hp << endl;
	cout << "Atk: " << atk << endl;
	cout << "Def: " << def << endl;
	cout << "Action: " << endl;
	cout << endl;
	cout << "C++{=====> ";
}
