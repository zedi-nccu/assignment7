#ifndef SNAKE_H
#define SNAKE_H

#include "gameObject.h"
#include <vector>

enum class Direction{
	UP,
	DOWN,
	RIGHT,
	LEFT
};



class Snake:public GameObject{
	public:
	Snake(Position Start);
	void grow();
	void update () override;
	bool check();
	Position getHeadPosition();
	const std::vector<Position>& getbody () const;
	Direction Dir;
	private:
	std::vector<Position> Body;
};
#endif 
