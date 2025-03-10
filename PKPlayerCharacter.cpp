#include "PKPlayerCharacter.h"

PlayerCharacter::PlayerCharacter()
PlayerCharacter::PlayerCharacter() : Cube()
{
public:
};

void update(float deltaTime){
    cube.position +=velocity*deltaTime;
};

void stopMovement(){
    velocity=glm::vec3(0.0f);
};
