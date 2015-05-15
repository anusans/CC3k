//
//  player.cpp
//  CS246 Final
//
//  Created by Anusan on 2014-11-22.
//  Copyright (c) 2014 Anusan. All rights reserved.
//

#include "player.h"
using namespace std;

//Constructor
Player::Player(int r, int c, int hp, int atk, int def): Character(r,c,hp,atk,def) {
	wallet = 0;
}

Player::~Player() {}


void Player::addGold(int val)
{
    wallet += val; //add to the Wallet field of Player
}

int Player::getGold() {
	return wallet;
}
