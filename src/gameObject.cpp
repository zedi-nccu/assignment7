// TODO implementation
#include "gameObject.h"

Position GameObject::getPosition() const{
	return _pos;
}
Icon GameObject::getIcon() const{
	return _icon;
}
GameObject:: GameObject(Position pos, Icon icon):_pos(pos), _icon(icon){
}
void GameObject:: update(){}
