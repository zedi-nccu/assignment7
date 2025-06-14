#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <termios.h>
#include <vector>
#include "view.h"
#include "gameObject.h"
#include "snake.h"
#include "food.h"
class Controller{

public:
       
    Controller(View&);
    void run();
private:
    void checkCollision();
    void createNewfood();
    void handleInput(int);
    void update();

    // Model
    Snake* _snake;
    food* _food;

    // View
    View& _view; 
    bool _gameOver=false;
};

static struct termios old_termios, new_termios;
void reset_terminal();
void configure_terminal();
int read_input();

#endif
