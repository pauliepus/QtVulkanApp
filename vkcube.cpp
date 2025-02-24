#include "vkcube.h"
#include "VkTrianglesurface.h"

VkCube::VkCube() {

    VkTriangleSurface Top;
    VkTriangleSurface Middle;
    VkTriangleSurface LeftMiddle;
    VkTriangleSurface RightMiddle;
    VkTriangleSurface UnderMiddle;
    VkTriangleSurface Bottom;

    Top.rotate(1.0f,1.0f,0.0f,0.0f); //makes flat
    Top.move(0.0f,1.0f,0.0f); // moves to top.

    Middle.rotate(0.5f,0.0f,0.0f,0.0f); //testing
}

