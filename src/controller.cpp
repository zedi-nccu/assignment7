#include <iostream>
#include <ctime>
#include <thread>
#include <unistd.h>
#include <termios.h>
#include <cctype>

#include "environment.h"
#include "controller.h"
#include "gameObjectFactory.h"
#include "iconFactory.h"

Controller::Controller(View& view) : _view(view){
	_snake=GameObjectFactory::createSnake();
	createNewfood();
}

void Controller::run() {
    // initial setup
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);
    configure_terminal();

    // init state
    int input = -1;
    clock_t start, end;
    
    // Main loop
    while (!_gameOver) {
        start = clock();
        // game loop goes here
        input = read_input();

        // ESC to exit program
        if(input==27)break;

        this->handleInput(input);
	_snake->update();
	checkCollision();
        _view.resetLatest();
	_view.updateGameObject(_snake);
        Icon bodyicon=IconFactory::createSnakeBodyIcon();
	const auto& body=_snake->getbody();
	for(size_t i=1;i<body.size();++i){
		GameObject bodypart(body[i], bodyicon);
		_view.updateGameObject(&bodypart);
	}
	_view.updateGameObject(_food);


        _view.render();


        end = clock();

        // frame rate normalization
        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
        if (time_taken > SPF) continue;
        int frameDelay = int((SPF - time_taken) * 1000); // 0.1 seconds
        if(frameDelay > 0) std::this_thread::sleep_for(std::chrono::milliseconds(frameDelay)); // frame delay
    }

}
void Controller::createNewfood(){
	bool onSnake=false;
	Position foodpos;
	do{
		onSnake=false;
		foodpos={rand()%GAME_WINDOW_WIDTH, rand()%GAME_WINDOW_HEIGHT};
		const auto& snakebody= _snake->getbody();
		for(const auto& part: snakebody){
			if(foodpos==part){
				onSnake=true;
				break;
			}
		}
	}while(onSnake);
	_food=new food(foodpos);
}


void Controller::checkCollision(){
	if(_snake->check()){
		_gameOver=true;
		return;
	}
	if(_snake->getHeadPosition().x()==_food->getPosition().x()&&
			_snake->getHeadPosition().y()==_food->getPosition().y()){
		_snake->grow();
		delete _food;
		createNewfood();
	}
}



void Controller::handleInput(int keyInput){

    // If there is no input, do nothing.
    if(keyInput==-1)return;
    keyInput=tolower(keyInput);
    switch(keyInput){
	     case 'w':
            if (_snake->Dir != Direction::DOWN) _snake->Dir = Direction::UP;
            break;
        case 's':
            if (_snake->Dir != Direction::UP) _snake->Dir = Direction::DOWN;
            break;
        case 'a':
            if (_snake->Dir != Direction::RIGHT) _snake->Dir = Direction::LEFT;
            break;
        case 'd':
            if (_snake->Dir != Direction::LEFT) _snake->Dir = Direction::RIGHT;
            break;
    }
}

    

    // TODO 
    // handle key events.


void Controller::update(){

}
void reset_terminal() {
    printf("\e[m"); // reset color changes
    printf("\e[?25h"); // show cursor
    fflush(stdout);
    tcsetattr(STDIN_FILENO, TCSANOW, &old_termios);
}

// terminal initial configuration setup
void configure_terminal() {
    tcgetattr(STDIN_FILENO, &old_termios);
	new_termios = old_termios; // save it to be able to reset on exit
    
    new_termios.c_lflag &= ~(ICANON | ECHO); // turn off echo + non-canonical mode
    new_termios.c_cc[VMIN] = 0;
    new_termios.c_cc[VTIME] = 0;

    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);

    printf("\e[?25l"); // hide cursor
    std::atexit(reset_terminal);
}


int read_input() {
    fflush(stdout);
   	char buf[4096]; // maximum input buffer
	int n = read(STDIN_FILENO, buf, sizeof(buf));
    return n > 0 ? buf[n - 1] : -1;
}

