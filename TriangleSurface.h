#ifndef TRIANGLESURFACE_H
#define TRIANGLESURFACE_H

#include <string>
#include "VisualObject.h"

//Defaults to a quad, but can read a mesh from file
class TriangleSurface : public VisualObject
{
public:
    float y;
    float x;
    TriangleSurface();
    TriangleSurface(const std::string& filename);
    // void constructPlane();
};

#endif // TRIANGLESURFACE_H
