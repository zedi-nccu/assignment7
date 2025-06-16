// TODO implementation
#include "gameObjectFactory.h"
#include "environment.h"
#include <cstdlib>
#include <ctime>

Snake* GameObjectFactory::createSnake(){
	return new Snake({GAME_WINDOW_WIDTH/2,GAME_WINDOW_HEIGHT/2});
}
food* GameObjectFactory::createfood(){
	srand(time(0));
	Position pos ={rand()%GAME_WINDOW_WIDTH, rand()%GAME_WINDOW_HEIGHT};
	return new food(pos);
}

