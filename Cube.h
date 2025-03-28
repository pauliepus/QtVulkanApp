#ifndef CUBE_H
#define CUBE_H


#include <string>
#include "VisualObject.h"

class Cube : public VisualObject
{

public:
    Cube();
    Cube(std::string name);

    // /* Returns Player Position */
    // QVector3D getPlayerPosition(VisualObject* Player){return Player->mMatrix.column(3).toVector3D();}

    // QVector3D playerPos = getPlayerPosition(Player);

};

#endif // CUBE_H
