#include "Door.h"
#include <fstream>
#include <QDebug>

Door::Door() : VisualObject()
{
    // Base vertices for the plus sign in the X-Y plane (center at origin)
    Vertex v0{-0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f};  // Left
    Vertex v1{0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f};   // Right
    Vertex v2{0.0f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f};   // Top
    Vertex v3{0.0f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f};  // Bottom

    // Vertices slightly above the base along the Z-axis (elevating the plus sign)
    Vertex v4{-0.5f, 0.0f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f};  // Left top, elevated
    Vertex v5{0.5f, 0.0f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f};   // Right top, elevated
    Vertex v6{0.0f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f};   // Top center, elevated
    Vertex v7{0.0f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f};  // Bottom center, elevated

    // The two center vertices
    Vertex v9{0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f};   // Bottom center vertex
    Vertex v10{0.0f, 0.0f, 0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f};  // Top center vertex

    // Right Wall
    mVertices.push_back(v9);   // Center bottom
    mVertices.push_back(v10);  // Center top
    mVertices.push_back(v1);   // Lower right

    mVertices.push_back(v1);   // Lower right
    mVertices.push_back(v5);   // Upper right
    mVertices.push_back(v10);  // Center top

    // Left Wall
    mVertices.push_back(v9);   // Center bottom
    mVertices.push_back(v10);  // Center top
    mVertices.push_back(v0);   // Lower left

    mVertices.push_back(v0);   // Lower left
    mVertices.push_back(v4);   // Upper left
    mVertices.push_back(v10);  // Center top

    // Top Wall
    mVertices.push_back(v9);   // Center bottom
    mVertices.push_back(v10);  // Center top
    mVertices.push_back(v2);   // Lower top

    mVertices.push_back(v2);   // Lower top
    mVertices.push_back(v6);   // Upper top
    mVertices.push_back(v10);  // Center top

    // Bottom Wall
    mVertices.push_back(v9);   // Center bottom
    mVertices.push_back(v10);  // Center top
    mVertices.push_back(v3);   // Lower bottom

    mVertices.push_back(v3);   // Lower bottom
    mVertices.push_back(v7);   // Upper bottom
    mVertices.push_back(v10);  // Center top
}
