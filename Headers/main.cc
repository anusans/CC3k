/*
 * main.cc
 * CS246 Assignment 5 (CC3k)
 * Chaewoon Park (c39park) & Anusan Sivakumaran (a26sivak)
 */
#include <iostream>
#include <string>
#include <sstream>
#include "map.h"
#include "cell.h"
#include "entity.h"
#include "mover.h"
#include "character.h"
#include "player.h"
#include "display.h"
#include "status.h"
#include "shade.h"
#include "drow.h"
#include "vampire.h"
#include "troll.h"
#include "goblin.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "orc.h"
#include "merchant.h"
#include "halfling.h"
#include "dragon.h"
#include "potion.h"
#include "gold.h"
using namespace std;

//Global variables that store state of game
bool running = true;
bool gameOn = true;
bool dead = false;
bool quit = false;
string cmd;

//Miscellanious global variables
bool angryMerch = false; //Merchant hostility
int floorNum; //floor number
int stairR; //Row of stairs
int stairC; //Column of stairs
int numOfE = 20; //Counter for number of enemies to ensure 20 spawn total

int main() {
	//Game restart loop (only loops when user chooses to restart game)
	while (running) {

		//Game initialization
		Player *thePlayer;
		running = true;
		gameOn = true;
		dead = false;
		quit = false;
		angryMerch = false;

		//Starting Menu
		cout << "Welcome to Chamber Crawler 3000!" << endl << endl;
		cout << "Please select the race of your hero." << endl << endl;
		cout << "s - Shade  : 125 HP / 25 Atk / 25 Def" << endl;
		cout << endl;
		cout << "d - Drow   : 150 HP / 25 AtK / 15 Def" << endl;
		cout << "	All potion effects magnified by 1.5x" << endl;
		cout << endl;
		cout << "v - Vampire:  50 HP / 25 AtK / 25 Def" << endl;
		cout << "	Gain 5 HP every attack" << endl;
		cout << "	...but they are allergic to dwarves!" << endl;
		cout << endl;
		cout << "t - Troll  : 120 HP / 25 Atk / 15 Def" << endl;
		cout << "	Gain 5 HP every turn up to 120 HP" << endl;
		cout << endl;
		cout << "g - Goblin : 110 HP / 15 Atk / 20 Def" << endl;
		cout << "	Steal 5 gold from every slain enemy" << endl;
		cout << endl;
		cout << "q - Quit game" << endl << endl;
		
		//Starting Menu Loop	
		while (1) {
			cin >> cmd; //Take in command from stdin
	
			//Choosing race and constructing player object
			if (cmd == "s") {
				//Shade
				cout << "You have chosen Shade." << endl;
				thePlayer = new Shade(3, 4);
				break;
			} else if (cmd == "d") {
				//Drow
				cout << "You have chosen Drow." << endl;
				thePlayer = new Drow(3, 4);
				break;
			} else if (cmd == "v") {
				//Vampire
				cout << "You have chosen Vampire." << endl;
				thePlayer = new Vampire(3, 4);
				break;
			} else if (cmd == "t") {
				//Troll
				cout << "You have chosen Troll." << endl;
				thePlayer = new Troll(3, 4);
				break;
			} else if (cmd == "g") {
				//Goblin
				cout << "You have chosen Goblin." << endl;
				thePlayer = new Goblin(3, 4);
				break;
			} else if (cmd == "q") {
				running = false;
				break;
			} else {
				cout << "Please choose a valid response." << endl;
			}
		//if user chooses to quit, running loop ends and program ends		
		}
		if (running == false) {
			break;
		}
		
		//Floor Initialization starts here

		//Controls main map grid and related functions
		Map *theMap = new Map();
		theMap->createMap();
		
		//Controls what gets printed to user
		Display *theDisplay = new Display(theMap, thePlayer);
	
		//Controls general state of game and enemy AI
		Status *theStatus = new Status(theMap, thePlayer);
	
		//Loops for each of the 5 floors
		for (floorNum = 1; floorNum<6; floorNum++) {

			//Generation/spawning of player/stairs/potions/gold/enemies
			theMap->generate(thePlayer);			
		
			theDisplay->print();

			//Turn loop, loops after every turn
			while (gameOn) {
				cin >> cmd;

				//player location
				int pR = thePlayer->getRow();
				int pC = thePlayer->getCol();
				
				//Takes in commands

				//Movement commands
				if (cmd == "no") {
					Mover::shift(pR-1, pC, thePlayer, theMap);
				} else if (cmd == "so") {
					Mover::shift(pR+1, pC, thePlayer, theMap);
				} else if (cmd == "ea") {	
					Mover::shift(pR, pC+1, thePlayer, theMap);
				} else if (cmd == "we") {
					Mover::shift(pR, pC-1, thePlayer, theMap);
				} else if (cmd == "ne") {
					Mover::shift(pR-1, pC+1, thePlayer, theMap);
				} else if (cmd == "nw") {
					Mover::shift(pR-1, pC-1, thePlayer, theMap);
				} else if (cmd == "se") {
					Mover::shift(pR+1, pC+1, thePlayer, theMap);
				} else if (cmd == "sw") {
					Mover::shift(pR+1, pC-1, thePlayer, theMap);

				//Use potion commands
				} else if (cmd == "u") {
					cin >> cmd;
	
					if (cmd == "no" && theMap->hasOccupant(pR-1,pC)) {
						Potion *myPot;
						myPot=dynamic_cast<Potion*>(theMap->getOccupant(pR-1,pC));
						if (myPot) {
							myPot->usePotion(thePlayer);
							theMap->despawn(pR-1,pC);
						}
					} else if (cmd == "so" && theMap->hasOccupant(pR+1,pC)) {
						Potion *myPot;
						myPot=dynamic_cast<Potion*>(theMap->getOccupant(pR+1,pC));
						if (myPot) {
							myPot->usePotion(thePlayer);
							theMap->despawn(pR+1,pC);
						}
					} else if (cmd == "ea" && theMap->hasOccupant(pR,pC+1)) {
						Potion *myPot;
						myPot=dynamic_cast<Potion*>(theMap->getOccupant(pR,pC+1));
						if (myPot) {
							myPot->usePotion(thePlayer);
							theMap->despawn(pR,pC+1);
						}
					} else if (cmd == "we" && theMap->hasOccupant(pR,pC-1)) {
						Potion *myPot;
						myPot=dynamic_cast<Potion*>(theMap->getOccupant(pR,pC-1));
						if (myPot) {
							myPot->usePotion(thePlayer);
							theMap->despawn(pR,pC-1);
						}
					} else if (cmd == "ne" && theMap->hasOccupant(pR-1,pC+1)) {
						Potion *myPot;
						myPot=dynamic_cast<Potion*>(theMap->getOccupant(pR-1,pC+1));
						if (myPot) {
							myPot->usePotion(thePlayer);
							theMap->despawn(pR-1,pC+1);
						}
					} else if (cmd == "nw" && theMap->hasOccupant(pR-1,pC-1)) {
						Potion *myPot;
						myPot=dynamic_cast<Potion*>(theMap->getOccupant(pR-1,pC-1));
						if (myPot) {
							myPot->usePotion(thePlayer);
							theMap->despawn(pR-1,pC-1);
						}
					} else if (cmd == "se" && theMap->hasOccupant(pR+1,pC+1)) {
						Potion *myPot;
						myPot=dynamic_cast<Potion*>(theMap->getOccupant(pR+1,pC+1));
						if (myPot) {
							myPot->usePotion(thePlayer);
							theMap->despawn(pR+1,pC+1);
						}
					} else if (cmd == "sw" && theMap->hasOccupant(pR+1,pC-1)) {
						Potion *myPot;
						myPot=dynamic_cast<Potion*>(theMap->getOccupant(pR+1,pC-1));
						if (myPot) {
							myPot->usePotion(thePlayer);
							theMap->despawn(pR+1,pC-1);
						}
					}

				//Attack commands
				} else if (cmd == "a") {
					cin >> cmd;
	
					if (cmd == "no" && theMap->hasOccupant(pR-1,pC)) {
						Enemy *e;
						e=dynamic_cast<Enemy*>(theMap->getOccupant(pR-1,pC));
						if (e) {
							thePlayer->hit(*e);
						}
					} else if (cmd == "so" && theMap->hasOccupant(pR+1,pC)) {
						Enemy *e;
						e=dynamic_cast<Enemy*>(theMap->getOccupant(pR+1,pC));
						if (e) {
							thePlayer->hit(*e);
						}
					} else if (cmd == "ea" && theMap->hasOccupant(pR,pC+1)) {
						Enemy *e;
						e=dynamic_cast<Enemy*>(theMap->getOccupant(pR,pC+1));
						if (e) {
							thePlayer->hit(*e);
						}
					} else if (cmd == "we" && theMap->hasOccupant(pR,pC-1)) {
						Enemy *e;
						e=dynamic_cast<Enemy*>(theMap->getOccupant(pR,pC-1));
						if (e) {
							thePlayer->hit(*e);
						}
					} else if (cmd == "ne" && theMap->hasOccupant(pR-1,pC+1)) {
						Enemy *e;
						e=dynamic_cast<Enemy*>(theMap->getOccupant(pR-1,pC+1));
						if (e) {
							thePlayer->hit(*e);
						}
					} else if (cmd == "nw" && theMap->hasOccupant(pR-1,pC-1)) {
						Enemy *e;
						e=dynamic_cast<Enemy*>(theMap->getOccupant(pR-1,pC-1));
						if (e) {
							thePlayer->hit(*e);
						}
					} else if (cmd == "se" && theMap->hasOccupant(pR+1,pC+1)) {
						Enemy *e;
						e=dynamic_cast<Enemy*>(theMap->getOccupant(pR+1,pC+1));
						if (e) {
							thePlayer->hit(*e);
						}
					} else if (cmd == "sw" && theMap->hasOccupant(pR+1,pC-1)) {
						Enemy *e;
						e=dynamic_cast<Enemy*>(theMap->getOccupant(pR+1,pC-1));
						if (e) {
							thePlayer->hit(*e);
						}
					} else {
					}

				//restart and quit commands
				} else if (cmd == "r") {
					cout << "restart" << endl;
					gameOn = false;
					quit = true;
					break;
				} else if (cmd == "q") {
					cout << "Goodbye" << endl;
					gameOn = false;
					running = false;
					quit = true;
					break;

				//only accepts valid commands
				} else {
					cout << "Please enter a valid command." << endl;
				}
	
				//Checks for death, controls enemy AI
				theStatus->update();
				
				//Prints for user
				theDisplay->print();

				//If player dies, end game
				if (dead) {
					cout << "You have died." << endl;
					gameOn = false;
					break;
				}

				//If player reaches stairs, move on to next floor
				if (thePlayer->getRow() == stairR &&
					thePlayer->getCol() == stairC) {
					theMap->despawn(stairR, stairC);
					break;
				}

				//Troll heals 5 HP every turn (special ability)
				Troll *temp = dynamic_cast<Troll*>(thePlayer);
				if (temp) {
					temp->regen();
				}
			}
			//Clear potion boosts each floor
			thePlayer->setAtkB(0);
			thePlayer->setDefB(0);
		
			//Clear map after every floor
			for (int i=0; i<25; i++) {
				for (int j=0; j<79; j++) {
					Entity *temp = theMap->getOccupant(i,j);
					theMap->despawn(i, j);
					delete temp;
				}
			}

			if (dead) {
				break;
			}

			if (quit) {
				break;
			}

			cout << endl;

		} 

		//End game display
		if (floorNum > 5) {
			cout << "Congratulations, you have won!" << endl;
			cout << "Score: " << thePlayer->getGold() << " gold" << endl;
		}
		//Natural endgame (without manual quit or restart)
		if (quit == false) {
			cout << "Play again? (y/n)" << endl;
			cin >> cmd;
			if (cmd == "n") {
				cout << "Thanks for playing!" << endl;
				running = false;
				break;
			} else if (cmd == "y") {
				cout << "Respawn!" << endl;
			} else {
				cout << "Please choose y or n." << endl;
			}
		}
	}
}
