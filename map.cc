/*
 * map.cc
 * CS246 Assignment 5 (CC3k)
 * Chaewoon Park (c39park) & Anusan Sivakumaran (a26sivak)
 */
#include "map.h"

using namespace std;

//Variables
extern int stairR; //row value of the staircase to next level
extern int stairC; //column value of the staircase to next level
extern int numOfE; //number of Enemies

//Method
void Map::createMap() {
	ifstream infile ("map.txt"); //reading from a predetermined map file (Future DLC Use)
	for (int i=0; i<25; i++) {
		string row = "0";
		getline(infile, row);
		char col[80];
		strcpy(col, row.c_str());
		for (int j=0; j<79; j++) {
			floorMap[i][j] = new Cell(col[j], i, j);
		}
	}
    
    //Array of Room Pointers (each Room points to an array of floor tiles (Cells))
    //Rooms are counted chronologically from top left corner to bottom right corner
	room = new Cell**[5];
	room[0] = new Cell*[104]; //Room 1
	room[1] = new Cell*[201]; //Room 2
	room[2] = new Cell*[36]; //Room 3
	room[3] = new Cell*[147]; //Room 4
	room[4] = new Cell*[150]; //Room 5

    //Initlizing the floor tiles
    
    //Room 1
	for (int i=0; i<4; i++) {
		for (int j=0; j<26; j++) {
			room[0][(i*26)+j] = floorMap[i+3][j+3];
		}
	}

	//Room 2
	for (int i=0; i<2; i++) {
		for (int j=0; j<23; j++) {
			room[1][(i*23)+j] = floorMap[i+3][j+39];
		}
	}
	for (int j=0; j<31; j++) {
		room[1][j+46] = floorMap[5][j+39];
	}
	for (int j=0; j<34; j++) {
		room[1][j+46+31] = floorMap[6][j+39];
	}
	for (int i=0; i<6; i++) {
		for (int j=0; j<15; j++) {
			room[1][((i*15)+j)+46+31+34] = floorMap[i+7][j+61];
		}
	}

    //Room 3
	for (int i=0; i<3; i++) {
		for (int j=0; j<12; j++) {
			room[2][(i*12)+j] = floorMap[i+10][j+38];
		}
	}

    //Room 4
	for (int i=0; i<7; i++) {
		for (int j=0; j<21; j++) {
			room[3][(i*21)+j] = floorMap[i+15][j+4];
		}
	}

    //Room 5
	for (int i=0; i<3; i++) {
		for (int j=0; j<11; j++) {
			room[4][(i*11)+j] = floorMap[i+16][j+65];
		}
	}
	for (int i=0; i<3; i++) {
		for (int j=0; j<39; j++) {
			room[4][((i*39)+j)+33] = floorMap[i+19][j+37];
		}
	}
}

//Constructor
Map::Map() {
	floorMap = new Cell**[25];
	for (int i=0; i<25; i++) {
		floorMap[i] = new Cell*[79];
	}

	for (int i=0; i<25; i++) {
		for (int j=0; j<79; j++) {
			floorMap[i][j] = NULL;
		}
	}

}

//Destructor
Map::~Map() {
	for (int i=0; i<25; i++) {
		delete [] floorMap[i];
	}
	delete [] floorMap;
}

//Methods

//This method is reponsible for printing the game Map every turn
void Map::printMap() {
	for (int i=0; i<25; i++) {
		for (int j=0; j<79; j++) {
			Entity *object = getOccupant(i,j);
			if (object != NULL) {
				if (object->getType() == "Human") {
					cout << "H";
				} else if (object->getType() == "Dwarf") {
					cout << "D";
				} else if (object->getType() == "Elf") {
					cout << "E";
				} else if (object->getType() == "Orc") {
					cout << "O";
				} else if (object->getType() == "Merchant") {
					cout << "M";
				} else if (object->getType() == "Halfling") {
					cout << "L";
				} else if (object->getType() == "Dragon") {
					cout << "D";
				} else if (object->getType() == "Potion") {
					cout << "P";
				} else if (object->getType() == "Gold") {
					cout << "G";
				} else {
					cout << "@";
				}
			} else {
				if (i == stairR && j == stairC) {
					cout << "\\";
				} else {
					cout << floorMap[i][j]->getType();
				}
			}
		}
		cout << endl;
	}
	
}

//Spawning an entity on a location
void Map::spawn(Entity *e, int r, int c) {
	floorMap[r][c]->setOccupant(e); //placing an entity ontop of a cell
}

//Spawning an entity directly to a cell
void Map::spawn(Entity *e, Cell *c) {
	c->setOccupant(e); //placing an entity ontop of a cell
}

//Removing a spawned entity on a location
void Map::despawn(int r, int c) {
	if (hasOccupant(r,c)) {
		floorMap[r][c]->setOccupant(NULL); //removing an entity ontop of a cell
	}
}

//Check if there is an entity ontop of the cell
bool Map::hasOccupant(int r, int c) {
	if (floorMap[r][c]->getOccupant() == NULL) {
		return false; //nothing is ontop of the cell
	} else {
		return true; //there is something ontop of the cell
	}
}

//Get the entity ontop of cell
Entity *Map::getOccupant(int r, int c) {
	return floorMap[r][c]->getOccupant();
}

//Set an entity to be ontop of a cell
void Map::setOccupant(int r, int c, Entity *e) {
	floorMap[r][c]->setOccupant(e);
}

//Geneation Method
void Map::generate(Player *thePlayer) {
	const int roomSize[5] = {104,201,36,147,150};
	int rRoom;
	int rTile;
	int tempRow;
	int tempCol;
	int pRoom;
	srand(time(NULL)); //set the random generator seed based on the clock time
	
	//First spawn the player in a random room, on a random floor tile
    pRoom = rand()%5;
	rTile = rand()%roomSize[pRoom];
	tempRow = room[pRoom][rTile]->getRow();
	tempCol = room[pRoom][rTile]->getCol();

	spawn(thePlayer, tempRow, tempCol); //spawn the player onto the map
	thePlayer->setRow(tempRow); //set Player X coordinate
	thePlayer->setCol(tempCol); //set Player Y coordinate

	//Next spawn the staircase, that is in a different room compared to where the Player is
    do {
		rRoom = rand()%5;
	} while (rRoom == pRoom);
	rTile = rand()%roomSize[rRoom];
	tempRow = room[rRoom][rTile]->getRow();
	tempCol = room[rRoom][rTile]->getCol();

	stairR = tempRow; //set staircase X coordinate
	stairC = tempCol; //set staircase Y coordinate

	//Spawn 10 random potions
    for (int i=0; i<10; i++) {
		int rNum = rand()%6;
		string potType;

		if (rNum == 0) {
			potType = "Restore Health";
		} else if (rNum == 1) {
			potType = "Boost Attack";
		} else if (rNum == 2) {
			potType = "Boost Defense";
		} else if (rNum == 3) {
			potType = "Poison Health";
		} else if (rNum == 4) {
			potType = "Wound Attack";
		} else if (rNum == 5) {
			potType = "Wound Defense";
		}

		Potion *p = new Potion(0, 0, potType); //soawn the potion onto the map
		randSpawn(p);
	}

    //Spawn 10 random gold hoards
	for (int i=0; i<10; i++) {
		int rNum = rand()%8;
		int value;

		if (rNum <= 4) {
			value = 2;
		} else if (rNum == 5) {
			value = 6;
		} else if (rNum > 5) {
			value = 1;
		}

		Gold *g = new Gold(0, 0, value);

		randSpawn(g);
	}
	
	//Spawn 20 random enemies
    for (int i=0; i<numOfE; i++) {
		int rNum = rand()%18;
		Enemy *e;

		if (rNum >= 0 && rNum <= 3) {
			e = new Human(0, 0); //Spawn a Human
		} else if (rNum >= 4 && rNum <= 6) {
			e = new Dwarf(0, 0); //Spawn a Dwarf
		} else if (rNum >= 7 && rNum <= 11) {
			e = new Halfling(0, 0); //Spawn a Hafling
		} else if (rNum == 12 || rNum == 13) {
			e = new Elf(0, 0); //Spawn an Elf
		} else if (rNum == 14 || rNum == 15) {
			e = new Orc(0, 0); //Spawn an Orc
		} else if (rNum == 16 || rNum == 17) {
			e = new Merchant(0, 0); //Spawn a Merchant
		}

		randSpawn(e); //randomize a spawn tile
	}

}

//randSpawn spawns an entity randomly on a vacant tile on the Map
void Map::randSpawn(Entity *e) {
	const int roomSize[5] = {104,201,36,147,150};
	int rRoom;
	int rTile;
	int tempRow;
	int tempCol;
	
	do {
		rRoom = rand()%5;
		rTile = rand()%roomSize[rRoom];
		tempRow = room[rRoom][rTile]->getRow();
		tempCol = room[rRoom][rTile]->getCol();
	} while (hasOccupant(tempRow, tempCol) ||
		(tempRow == stairR && tempCol == stairC));

	spawn(e, tempRow, tempCol); //spawn an Entity onto the map
	e->setRow(tempRow); //set X coordinate of the Entity
	e->setCol(tempCol); //set Y coordinate of the Entity

    //If the gold hoard has a value of 6, spawn a Dragon that protects the hoard on a vacant tile
    Gold *g = dynamic_cast<Gold*>(e);
	if (g && g->getVal() == 6) {
		int rNum = rand()%8;
		
		if (rNum == 0 && !hasOccupant(tempRow-1,tempCol) &&
			floorMap[tempRow-1][tempCol]->spawnable()) {
			Dragon *d = new Dragon(tempRow-1,tempCol,g);
			spawn(d,tempRow-1,tempCol);
			g->setOwner(d);
		} else if (rNum == 1 && !hasOccupant(tempRow+1,tempCol) &&
			floorMap[tempRow+1][tempCol]->spawnable()) {
			Dragon *d = new Dragon(tempRow+1,tempCol,g);
			spawn(d,tempRow+1,tempCol);
			g->setOwner(d);
		} else if (rNum == 2 && !hasOccupant(tempRow,tempCol+1) &&
			floorMap[tempRow][tempCol+1]->spawnable()) {
			Dragon *d = new Dragon(tempRow,tempCol+1,g);
			spawn(d,tempRow,tempCol+1);
			g->setOwner(d);
		} else if (rNum == 3 && !hasOccupant(tempRow,tempCol-1) &&
			floorMap[tempRow][tempCol-1]->spawnable()) {
			Dragon *d = new Dragon(tempRow,tempCol-1,g);
			spawn(d,tempRow,tempCol-1);
			g->setOwner(d);
		} else if (rNum == 4 && !hasOccupant(tempRow+1,tempCol+1) &&
			floorMap[tempRow+1][tempCol+1]->spawnable()) {
			Dragon *d = new Dragon(tempRow+1,tempCol+1,g);
			spawn(d,tempRow+1,tempCol+1);
			g->setOwner(d);
		} else if (rNum == 5 && !hasOccupant(tempRow+1,tempCol-1) &&
			floorMap[tempRow+1][tempCol-1]->spawnable()) {
			Dragon *d = new Dragon(tempRow+1,tempCol,g-1);
			spawn(d,tempRow+1,tempCol-1);
			g->setOwner(d);
		} else if (rNum == 6 && !hasOccupant(tempRow-1,tempCol+1) &&
			floorMap[tempRow-1][tempCol+1]->spawnable()) {
			Dragon *d = new Dragon(tempRow-1,tempCol+1,g);
			spawn(d,tempRow-1,tempCol+1);
			g->setOwner(d);
		} else if (rNum == 7 && !hasOccupant(tempRow-1,tempCol-1) &&
			floorMap[tempRow-1][tempCol-1]->spawnable()) {
			Dragon *d = new Dragon(tempRow-1,tempCol-1,g);
			spawn(d,tempRow-1,tempCol-1);
			g->setOwner(d);
		} else {}
		numOfE--;
	}
}
