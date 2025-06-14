// TODO implementation
#include "gameObjectFactory.h"
#include "enviroment.h"
#include <cstdlib>
#include <ctime>

Snake* GameObjectFactory::createSnake(){
	return new Snake({GAME_WINDOW_WIDTH,GAME_WINDOW_HEIGHT});
}
food* GameObjectFactory::createfood(){
	srand(time(0));
	Position pos ={rand()%GAME_WINDOW_WIDTH, rand()%GAME_WINDOW_HEIGHT};
	return new food(pos);
}

