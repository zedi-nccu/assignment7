#ifndef ELEMENT_H
#define ELEMENT_H

#include <vector>
#include "unit.h"
#include "icon.h"
#include <iostream>
class GameObject{

public:

    Position getPosition() const;
    Icon getIcon() const;
    virtual void update();
protected:

    Position _pos;
    Icon _icon;
};

#endif
