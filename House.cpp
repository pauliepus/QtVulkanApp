#include "House.h"
#include <fstream>
#include <QDebug>

House::House(): VisualObject()
{
    // Base vertices (4 at the bottom and 4 at the top)
    Vertex v0{0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f}; // Bottom-left-front
    Vertex v1{4.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 0.0f}; // Bottom-right-front
    Vertex v2{4.0f, 4.0f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, 1.0f}; // Bottom-right-back
    Vertex v3{0.0f, 4.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f}; // Bottom-left-back

    Vertex v4{0.0f, 0.0f, 2.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f}; // Top-left-front
    Vertex v5{4.0f, 0.0f, 2.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f}; // Top-right-front
    Vertex v6{4.0f, 4.0f, 2.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f}; // Top-right-back
    Vertex v7{0.0f, 4.0f, 2.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f}; // Top-left-back

    // Roof vertices (2 peak vertices)
    Vertex v8{2.0f, 0.0f, 4.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f}; // Left peak (triangle tip)
    Vertex v9{2.0f, 4.0f, 4.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f}; // Right peak (triangle tip)

    // Front wall
    mVertices.push_back(v0);  // Bottom-left-front
    mVertices.push_back(v1);  // Bottom-right-front
    mVertices.push_back(v4);  // Top-left-front

    mVertices.push_back(v4);  // Top-left-front
    mVertices.push_back(v5);  // Top-right-front
    mVertices.push_back(v1);  // Bottom-right-front

    // Back wall
    mVertices.push_back(v2);  // Bottom-right-back
    mVertices.push_back(v3);  // Bottom-left-back
    mVertices.push_back(v6);  // Top-right-back

    mVertices.push_back(v6);  // Top-right-back
    mVertices.push_back(v7);  // Top-left-back
    mVertices.push_back(v3);  // Bottom-left-back

    // Left wall
    mVertices.push_back(v0);  // Bottom-left-front
    mVertices.push_back(v3);  // Bottom-left-back
    mVertices.push_back(v4);  // Top-left-front

    mVertices.push_back(v4);  // Top-left-front
    mVertices.push_back(v7);  // Top-left-back
    mVertices.push_back(v3);  // Bottom-left-back

    // Right wall
    mVertices.push_back(v1);  // Bottom-right-front
    mVertices.push_back(v2);  // Bottom-right-back
    mVertices.push_back(v5);  // Top-right-front

    mVertices.push_back(v5);  // Top-right-front
    mVertices.push_back(v6);  // Top-right-back
    mVertices.push_back(v2);  // Bottom-right-back


}
