#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "view.h"
#include "controller.h"
#include "AnsiPrint.h"
/**
 * Print my id
 * */
void
PrintMyID(std::string studId) {

    std::string str = "ID: " + studId;
    std::cout << AnsiPrint(str.c_str(),YELLOW,RED, true, true) << std::endl << std::endl;
}



int main(){
    // TODO 
    // Integrate the Simple MVC Pattern to run the program.
    srand(time(0));
    View view;
    Controller controller(view);
    controller.run();
	

    // TODO
    // change to your student ID.
    PrintMyID("Writer::113703042");
    return 0;
}
