/*
 * cell.cc
 * CS246 Assignment 5 (CC3k)
 * Chaewoon Park (c39park) & Anusan Sivakumaran (a26sivak)
 */

#include "cell.h"
#include <cstddef>

Cell::Cell(char type, int row, int col): type(type), row(row), col(col) {
	occupant = NULL;
}
Cell::~Cell() {}

bool Cell::walkable() {
	if (type == '.' || type == '+' || type == '#') {
		return true;
	} else {
		return false;
	}
}

bool Cell::eWalkable() {
	if (type == '.') {
		return true;
	} else {
		return false;
	}
}

bool Cell::spawnable() {
	if (type == '.') {
		return true;
	} else {
		return false;
	}
}

char Cell::getType() {
	return type;
}

Entity * Cell::getOccupant() {
	return occupant;
}

void Cell::setOccupant(Entity *e) {
	occupant = e;
}

int Cell::getRow() {
	return row;
}

int Cell::getCol() {
	return col;
}
