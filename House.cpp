#include "House.h"
#include <fstream>
#include <QDebug>

House::House(): VisualObject()
{
    // Bottom vertices (yellow)
    Vertex v0{0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f};
    Vertex v1{4.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f};
    Vertex v2{4.0f, 2.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f};
    Vertex v3{0.0f, 2.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f};

    // 0.0f sideways, 2.0f upwards, 0.f inwards
    // Top vertices (red)
    Vertex v4{0.0f, 0.0f, 2.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f}; //botleft 1
    Vertex v5{4.0f, 0.0f, 2.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f}; //botright 2
    Vertex v6{4.0f, 2.0f, 2.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f}; //topright 3
    Vertex v7{0.0f, 2.0f, 2.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f}; //topleft 4

    // Roof vertices (black)

    Vertex v8{0.0f, 1.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};  // 2 units above left short side
    Vertex v9{4.0f, 1.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};  // 2 units above right short side


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

    // Triangle roof left
    mVertices.push_back(v4);  // Top-left-front
    mVertices.push_back(v8);  // tip 1
    mVertices.push_back(v7);  //

    // Triangle roof right
    mVertices.push_back(v9);  // tip 2
    mVertices.push_back(v5);  // Top-left-back
    mVertices.push_back(v6);  //

    // Roof bottom, 1 + roof bot 2
    mVertices.push_back(v9);  // tip 2
    mVertices.push_back(v5);  //
    mVertices.push_back(v4);  //

    mVertices.push_back(v9);  //
    mVertices.push_back(v4);  //
    mVertices.push_back(v8);  // tip 1

    // roof top
    mVertices.push_back(v9);  // tip 2
    mVertices.push_back(v7);  //
    mVertices.push_back(v8);  //

    mVertices.push_back(v9);  //
    mVertices.push_back(v7);  //
    mVertices.push_back(v6);  // tip 1
}
