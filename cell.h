/*
 * cell.h
 * CS246 Assignment 5 (CC3k)
 * Chaewoon Park (c39park) & Anusan Sivakumaran (a26sivak)
 */

#ifndef __CELL_H__
#define __CELL_H__
#include "entity.h"
#include "character.h"

class Cell {
	private:
		Entity *occupant; //pointer to what entity is on this cell
		char type; //whether it's a floor/passage/wall etc
		int row; //row of cell
		int col; //column of cell
	public:
		//Constructors and Destructors
		Cell(char type, int row, int col);
		~Cell();

		//Methods
		bool walkable(); //Whether player can walk on it
		bool eWalkable(); //Whether enemy can walk on it
		bool spawnable(); //Whether something can spawn on it
		
		//Getters and Setters
		char getType();
		Entity *getOccupant();
		void setOccupant(Entity *e);
		int getRow();
		int getCol();
};

#endif
