/*
 * display.h
 * CS246 Assignment 5 (CC3k)
 * Chaewoon Park (c39park) & Anusan Sivakumaran (a26sivak)
 */

#ifndef __DISPLAY_H__
#define __DISPLAY_H__
#include <string>
#include <iostream>
#include <iomanip>
#include "player.h"
#include "map.h"

class Display {
	private:
		Map *theMap; 
		Player * thePlayer;
		std::string pRace; //race of player
		int hp; //Player hp
		int atk; //Player atk
		int def; //Player def
		int gold; //Player gold
		
	public:
		//Constructor
		Display(Map *m, Player *p);

		//updates displayed values
		void update();

		//displays to user
		void print();
};

#endif
