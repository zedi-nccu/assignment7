#ifndef FOOD_H
#define FOOD_H

#include "gameObject.h"
#include "unit.h"

class food:public GameObject{
	public :
		food(Position pos);
		void respawn(Position newpos);
};
#endif
