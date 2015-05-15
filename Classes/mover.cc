/*
 * mover.cc
 * CS246 Assignment 5 (CC3k)
 * Chaewoon Park (c39park) & Anusan Sivakumaran (a26sivak)
 */
#include "mover.h"
#include "gold.h"

//Method

//Try to move the player onto the designated floor tile
bool Mover::shift(int r, int c, Player *p, Map *m){
	if (m->floorMap[r][c]->walkable() == false) {
		return false; //Player cannot walk onto this floor tile (i.e. Enemy on it etc.)
	} else if (m->hasOccupant(r,c) == true) {
		if (m->getOccupant(r,c)->getType() == "Gold") {
            //If the player is walking ontop of a gold hoard, pick it up (if possible) and add the amount
			Gold *myGold = dynamic_cast<Gold *>(m->getOccupant(r,c));
			if (myGold->pickupAble()) {
				p->addGold(myGold->getVal());
			} else {
				return false; //cannot pick up the gold
			}
		} else {
			return false;
		}
	}

	m->despawn(p->getRow(),p->getCol()); //despawn Player from the original floor tile
	m->spawn(p,r,c); //spawn the Player onto the new floor tile
	p->setRow(r); //set Player X coordinate
	p->setCol(c); //set Player Y coordinate

	return true;
}

//Try to move an enemy to the designated floor tile
bool Mover::shift(int r, int c, Enemy *e, Map *m){
	if (m->hasOccupant(r,c) == false && m->floorMap[r][c]->eWalkable()) {
		m->despawn(e->getRow(),e->getCol()); //despawn Enemy from the original floor tile
		m->spawn(e,r,c); //spawn Enemy onto the new floor tile
		e->setRow(r); //set Enemy X coordinate
		e->setCol(c); //set Enemy Y coordinate
		return true;
	} else {
		return false; //cannot move onto the floor tile
	}
}

//Randomly move the enemy around on the floor tiles of the current room
void Mover::randShift(Enemy *e, Map *m) {
	int r;
	int row = e->getRow();
	int col = e->getCol();
	while (1) {
		r = rand() % 9; //random 8 positions
		if (r == 0) {
			if (shift(row-1,col,e,m)) {
				break;
			}
		} else if (r == 1) {
			if (shift(row+1,col,e,m)) {
				break;
			}
		} else if (r == 2) {
			if (shift(row,col+1,e,m)) {
				break;
			}
		} else if (r == 3) {
			if (shift(row,col-1,e,m)) {
				break;
			}
		} else if (r == 4) {
			if (shift(row-1,col+1,e,m)) {
				break;
			}
		} else if (r == 5) {
			if (shift(row-1,col-1,e,m)) {
				break;
			}
		} else if (r == 6) {
			if (shift(row+1,col+1,e,m)) {
				break;
			}
		} else if (r == 7) {
			if (shift(row+1,col-1,e,m)) {
				break;
			}
		} else {
			break;
		}
	}
}
