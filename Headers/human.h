//
//  human.h
//  CS246 Final
//
//  Created by Anusan on 2014-11-24.
//  Copyright (c) 2014 Anusan. All rights reserved.
//

#ifndef __CS246_Final__human__
#define __CS246_Final__human__
#include <string>
#include "enemy.h"

class Human: public Enemy
{
	private:
		static const int MAX_HP;
		static const int START_ATK;
		static const int START_DEF;
	public:
    	Human(int r, int c);
    	~Human();
    	std::string getType();

		void hit(Player &p);
		void getHit(Shade &s);
		void getHit(Drow &d);
		void getHit(Vampire &v);
		void getHit(Troll &t);
		void getHit(Goblin &g);
};

#endif /* defined(__CS246_Final__human__) */
