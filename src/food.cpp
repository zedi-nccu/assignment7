#include "food.h"
#include "iconFactory.h"
food::food (Position pos){
	_pos=pos;
	_icon=IconFactory::createfood();
}
void food::respawn(Position newpos){
	_pos=newpos;
}
