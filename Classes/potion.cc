/*
 * potion.cc
 * CS246 Assignment 5 (CC3k)
 * Chaewoon Park (c39park) & Anusan Sivakumaran (a26sivak)
 */

#include "potion.h"
using namespace std;

//Constructor
Potion::Potion(int r, int c, string potType): Entity(r,c), potType(potType) {
	hp = 0;
	atk = 0;
	def = 0;

	if (potType == "Restore Health") {
		hp = 10; //Restore Health Potion
	} else if (potType == "Boost Attack") {
		atk = 5; //Boost Attack Potion
	} else if (potType == "Boost Defense") {
		def = 5; //Boost Defence Potion
	} else if (potType == "Poison Health") {
		hp = -10; //Poison Health Potion
	} else if (potType == "Wound Attack") {
		atk = -5; //Wound Attack Potion
	} else if (potType == "Wound Defense") {
		def = -5; //Wound Defence Potion
	}
}

//Destructor
Potion::~Potion(){ }

//Methods

//Gets

int Potion::getHP()
{
    return hp; // return the hp value of the potion
}

int Potion::getAtk()
{
    return atk; // return the atk value of a potion
}

int Potion::getDef()
{
    return def; // return the def value of a potion
}

string Potion::getPotType()
{
    return potType; // return the pot value of a potion (the name of the potion)
}

string Potion::getType() {
	return "Potion"; //return the type of Potion
}

//Player picks up a potion and uses it
void Potion::usePotion(Player *p) {	
	if (p->getType() == "Drow") {
        //Drow's special ability buffs stat boosts by 50%
		p->setHP(p->getHP() + (1.5*hp));
		p->setAtkB(p->getAtk() + 1.5*atk);
		p->setDefB(p->getDef() + 1.5*def);
	} else {
        //Boost stats normally to Player
		p->setHP(p->getHP() + hp);
		p->setAtkB(p->getAtkB() + atk);
		p->setDefB(p->getDefB() + def);
	}
}
