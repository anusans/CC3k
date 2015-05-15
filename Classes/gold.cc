/*
 * gold.cc
 * CS246 Assignment 5 (CC3k)
 * Chaewoon Park (c39park) & Anusan Sivakumaran (a26sivak)
 */

#include "gold.h"
using namespace std;

//Constructor
Gold::Gold(int r, int c, int val): Entity(r,c), val(val)  {
	if (val == 6) {
		canPickup = false; //If it's a dragon gold hoard set it so it can't be picked up by the Player
	} else {canPickup = true;}
	owner = NULL;
}

//Destructor
Gold::~Gold(){ }

//Methods

int Gold::getVal() {
	return val; //return the val field of Gold (Gold amount)
}

bool Gold::pickupAble() {
	return canPickup; //determine if the Gold can be picked up
}

void Gold::allowPickup() {
	canPickup = true; //after the gold hoard Dragon has been slain allow pick up (Always true otherwise)
}

string Gold::getType() {
	return "Gold"; //return the type of entity (Gold)
}

Dragon *Gold::getOwner() {
	return owner; //return the Dragon guarding this hoard (NULL otherwise)
}

void Gold::setOwner(Dragon *d) {
	owner = d; //set a Dragon to guard this hoard (Used in the game initialization and spawning)
}
