#ifndef PKPLAYERCHARACTER_H
#define PKPLAYERCHARACTER_H

#include "VisualObject.h"
#include "Input.h"
#include "Cube.h"

class PlayerCharacter : public VisualObject, Input, Cube
{
public:
    PlayerCharacter();


};



#endif // PKPLAYERCHARACTER_H
