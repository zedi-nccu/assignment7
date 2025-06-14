#include "food.h"
#include "iconFactory"
food::food (Position pos){
	_pos=pos;
	_icon=iconFactory::createFood();
}
void food::respawn(Position newpos){
	_pos=newpos;
}
