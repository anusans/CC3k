//
//  entity.cc
//  CS246 Final
//
//  Created by Anusan on 2014-11-22.
//  Copyright (c) 2014 Anusan. All rights reserved.
//

#include "entity.h"

//Constructor
Entity::Entity(int r, int c): r(r), c(c) { }

//Destrutor
Entity::~Entity() { }

//Methods

int Entity::getRow()
{
    return r; //return the the row value of Entity
}

int Entity::getCol()
{
    return c; //return the column value of Entity
}

void Entity::setRow(int row)
{
    r = row; //set the row value of Entity to a new value
}

void Entity::setCol(int col)
{
    c = col; //set the row value of Entity to a new value
}

