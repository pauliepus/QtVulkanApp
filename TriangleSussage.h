#ifndef TRIANGLESUSSAGE_H
#define TRIANGLESUSSAGE_H

#include <string>
#include "VisualObject.h"

class TriangleSussage : public VisualObject
{
public:
    TriangleSussage();
    std::vector<Vertex> getVertices();
    TriangleSussage(const std::string& filename);
    void constructPlane();
};

#endif // TRIANGLESUSSAGE_H
