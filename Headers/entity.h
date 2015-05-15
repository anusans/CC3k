//
//  entity.h
//  CS246 Final
//
//  Created by Anusan on 2014-11-22.
//  Copyright (c) 2014 Anusan. All rights reserved.
//

#ifndef CS246_Final_entity_h
#define CS246_Final_entity_h
#include <string>
#include <iostream>
#include <sstream>

class Entity
{
  private:
    int r; //row
    int c; //column
  public:
    Entity(int r, int c);
    virtual ~Entity();
    int getRow();
    int getCol();
    void setRow(int row);
    void setCol(int col);
	virtual std::string getType() = 0;
};

#endif
