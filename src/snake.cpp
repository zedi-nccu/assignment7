#include "snake.h"
#include "environment.h"
#include "iconFactory.h"
#include <type_traits>
#include <vector>
Snake::Snake(Position Start):Dir(Direction::RIGHT){
	_pos=Start;
	Body.push_back(_pos);
	_icon=IconFactory::createSnakeHeadIcon();
}
void Snake::grow(){
	Body.push_back(Body.back());
}
void Snake::update(){
	Position newhead=getHeadPosition();
	switch(Dir){
		case Direction::UP: newhead.y()--; break;
		case Direction::DOWN: newhead.y()++; break;
		case Direction::RIGHT:newhead.x()++; break;
		case Direction::LEFT: newhead.x()--; break;
	}
	_pos=newhead;
	Body.insert(Body.begin(),newhead);
	Body.pop_back();
}
bool Snake::check(){
	Position head=getHeadPosition();
	if(head.x()<0||head.x()>=GAME_WINDOW_WIDTH||head.y()<0||head.y()>=GAME_WINDOW_HEIGHT){
		return true;
	}
	for(int i=1;i<Body.size();i++){
		if(Body[i]==head){
			return true;
		}
	}
	return false;
}
Position Snake::getHeadPosition(){
	return _pos;
}
const std::vector<Position>& Snake::getbody() const{
	return Body;
}


