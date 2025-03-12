#ifndef PKPLAYERCHARACTER_H
#define PKPLAYERCHARACTER_H

#include "Input.h"
#include "Cube.h"

class PlayerCharacter : public Input, Cube
{
public:
    PlayerCharacter();
    bool isColliding=false; //to stop movement
};



#endif // PKPLAYERCHARACTER_H
