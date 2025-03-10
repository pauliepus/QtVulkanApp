#ifndef CUBE_H
#define CUBE_H


#include <string>
#include "VisualObject.h"

class Cube : public VisualObject
{
public:
    Cube();
    Cube(const std::string& filename);
};

#endif // CUBE_H
