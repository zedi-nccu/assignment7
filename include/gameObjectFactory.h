// TODO 
// Finish the declaration of GameObjectFactory that
// 1. offers some methods to create a GameObject.
// 2. encapsulates the constructor from the caller. 
#ifndef GAMEOBJECTFACTORY_H
#define GAMEOBJECTFACTORY_H
#include "snake.h"
#include "food.h"
class GameObjectFactory{
	public:
		static Snake* createSnake();
		static food* createfood();
	private:
		GameObjectFactory(){}
};
#endif
