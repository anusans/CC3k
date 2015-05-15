/*
 * status.cc
 * CS246 Assignment 5 (CC3k)
 * Chaewoon Park (c39park) & Anusan Sivakumaran (a26sivak)
 */

#include "status.h"
#include "mover.h"
#include "dragon.h"
#include "gold.h"
#include <cstdlib>
using namespace std;

extern bool angryMerch;

Status::Status(Map *m, Player *p):
	theMap(m), thePlayer(p) {}

Status::~Status() {}

void Status::update() {
	extern bool dead;

	//Goes through each tile of map
	for (int i=0; i<25; i++) {
		for (int j=0; j<79; j++) {

			//Check if tile has entity
			if (theMap->hasOccupant(i, j)) {
				//If enemy
				Enemy *myE;
				myE = dynamic_cast<Enemy*>(theMap->getOccupant(i,j));
				if (myE) {
					//Checks if enemy has died
					if (myE->getHP() <= 0) {
						if (myE->getType() == "Human" ||
							myE->getType() == "Merchant") {
							thePlayer->addGold(4);
						//if dragon, releases hoard
						} else if (myE->getType() == "Dragon") {
							Dragon *d = dynamic_cast<Dragon*>(myE);
							d->releaseGold();
						//Enemy loot
						} else {
							if (rand()%2 == 1) {
								thePlayer->addGold(1);
							} else {
								thePlayer->addGold(2);
							}
						}
						//Removes from game
						theMap->despawn(i,j);
						delete myE;
						return;
					}
					
					//Enemy attack or move
					//Merchants only attack if hostile
					if (myE->getType() != "Merchant" ||
						(myE->getType() == "Merchant" && angryMerch)) { 
						if (theMap->hasOccupant(i-1,j) && 
						theMap->getOccupant(i-1,j) == thePlayer) {
							myE->hit(*thePlayer);
						} else if (theMap->hasOccupant(i+1,j) &&	
						theMap->getOccupant(i+1,j) == thePlayer) {
							myE->hit(*thePlayer);
						} else if (theMap->hasOccupant(i,j+1) &&	
						theMap->getOccupant(i,j+1) == thePlayer) {
							myE->hit(*thePlayer);
						} else if (theMap->hasOccupant(i,j-1) &&	
						theMap->getOccupant(i,j-1) == thePlayer) {
							myE->hit(*thePlayer);
						} else if (theMap->hasOccupant(i-1,j+1) &&
						theMap->getOccupant(i-1,j+1) == thePlayer) {
							myE->hit(*thePlayer);
						} else if (theMap->hasOccupant(i-1,j-1) &&	
						theMap->getOccupant(i-1,j-1) == thePlayer) {
							myE->hit(*thePlayer);
						} else if (theMap->hasOccupant(i+1,j+1) &&	
						theMap->getOccupant(i+1,j+1) == thePlayer) {
							myE->hit(*thePlayer);
						} else if (theMap->hasOccupant(i+1,j-1) &&	
						theMap->getOccupant(i+1,j-1) == thePlayer) {
							myE->hit(*thePlayer);
						} else if (myE->getType() != "Dragon") {
							Mover::randShift(myE, theMap);
						}
					} else if (myE->getType()=="Merchant" && !angryMerch) {
						Mover::randShift(myE, theMap);
					}			
				}

				//If gold
				Gold *myG;
				myG = dynamic_cast<Gold*>(theMap->getOccupant(i,j));
				if (myG) {
					//Dragon protecting gold
					if (myG->pickupAble() == false) {	
						if (theMap->hasOccupant(i-1,j) && 
						theMap->getOccupant(i-1,j) == thePlayer) {
							myG->getOwner()->hit(*thePlayer);
						} else if (theMap->hasOccupant(i+1,j) &&	
						theMap->getOccupant(i+1,j) == thePlayer) {
							myG->getOwner()->hit(*thePlayer);
						} else if (theMap->hasOccupant(i,j+1) &&	
						theMap->getOccupant(i,j+1) == thePlayer) {
							myG->getOwner()->hit(*thePlayer);
						} else if (theMap->hasOccupant(i,j-1) &&	
						theMap->getOccupant(i,j-1) == thePlayer) {
							myG->getOwner()->hit(*thePlayer);
						} else if (theMap->hasOccupant(i-1,j+1) &&
						theMap->getOccupant(i-1,j+1) == thePlayer) {
							myG->getOwner()->hit(*thePlayer);
						} else if (theMap->hasOccupant(i-1,j-1) &&	
						theMap->getOccupant(i-1,j-1) == thePlayer) {
							myG->getOwner()->hit(*thePlayer);
						} else if (theMap->hasOccupant(i+1,j+1) &&	
						theMap->getOccupant(i+1,j+1) == thePlayer) {
							myG->getOwner()->hit(*thePlayer);
						} else if (theMap->hasOccupant(i+1,j-1) &&	
						theMap->getOccupant(i+1,j-1) == thePlayer) {
							myG->getOwner()->hit(*thePlayer);
						}
					}
				}
			}
		}
	}

	//Checks for player death
	if (thePlayer->getHP() <= 0) {
		dead = true;
		return;
	}
}
