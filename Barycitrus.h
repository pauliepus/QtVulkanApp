#ifndef BARYCITRUS_H
#define BARYCITRUS_H
#include "HeightMap.h"

class Barycitrus
{
public:
    Barycitrus();

 float getPositionInTerrain(HeightMap Terrain, float Positionx, float PositionZ);
    QVector3D BarycentricCoordinetes(QVector2D ObjPos, QVector2D p0, QVector2D p1, QVector2D p2);
};

#endif // BARYCITRUS_H
