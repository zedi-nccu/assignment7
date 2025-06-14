#include "iconFactory.h"

Icon IconFactory::createSnakeHeadIcon(){
	Cell head(GREEN, "@");
	return {{head}};
}
Icon IconFactory::createfood(){
	return{{Cell(RED, "X")}};
}
Icon IconFactory:: createSnakeBodyIcon(){
	return {{Cell(GREEN, "O")}};
}



