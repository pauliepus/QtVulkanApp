#ifndef PKPLAYERCHARACTER_H
#define PKPLAYERCHARACTER_H

#include "VisualObject.h"
#include "Input.h"
#include "Cube.h"

{
public:
    Cube cube;

    PlayerCharacter();
    void update(float deltaTime);
    void stopMovement();
    void handleInput(int key);

};



#endif // PKPLAYERCHARACTER_H
