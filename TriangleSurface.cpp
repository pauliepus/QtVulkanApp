#include "TriangleSurface.h"
#include <fstream>
#include <QDebug>

TriangleSurface::TriangleSurface() : VisualObject()
{
    //red front-low-left, point at origo
    Vertex v1{0.0f,   0.0f,  0.0f,   1.0f, 0.0f, 0.0f,   0.0f, 0.0f};
    //green front-low-right green, point x+1
    Vertex v2{1.0f,   0.0f,  0.0f,   0.0f, 1.0f, 0.0f,   0.0f, 0.0f};
    //blue front-top-right, point y+1
    Vertex v3{0.0f,   1.0f,  0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f};
    //r+g front-    x+1,y+1,0,
    Vertex v4{1.0f,   1.0f,  0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f};
    //blue bak v3 -low-right x+1,z-1
    Vertex v5{0.0f,  1.0f, -1.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f};
    //red bak-v1
    Vertex v6{0.0f,  0.0f, -1.0f,   1.0f, 0.0f, 0.0f,   0.0f, 0.0f};
    //green bak-v2
    Vertex v7{1.0f,  0.0f, -1.0f,   0.0f, 1.0f, 0.0f,   0.0f, 0.0f};
    //r+g bak v4
    Vertex v8{1.0f,  1.0f, -1.0f,   1.0f, 1.0f, 0.0f,   0.0f, 0.0f};



    //Pushing 1st triangle,
    mVertices.push_back(v1); //front-low-left
    mVertices.push_back(v2); //front-low-right
    mVertices.push_back(v3); //front-top-right

    //Grid fill thing
    //husk, xz og ikke XY
    Vertex origo{0.0f, 0.0f, 0.0f, 0.0f, 0.5f, 0.0f, 0.0f, 0.0f};
    Vertex y{0.0f, 50.0f, 0.0f, 0.0f, 0.5f, 0.0f, 0.0f, 0.0f};
    Vertex x{50.0f, 0.0f, 0.0f, 0.0f, 0.5f, 0.0f, 0.0f, 0.0f};
    Vertex xy{50.0f, 50.0f, 0.0f, 0.0f, 0.5f, 0.0f, 0.0f, 0.0f};

    mVertices.push_back(origo);
    mVertices.push_back(y);
    mVertices.push_back(x);

    mVertices.push_back(y);
    mVertices.push_back(xy);
    mVertices.push_back(x);


    //Temporary scale and positioning
    mMatrix.scale(0.5f);
    mMatrix.translate(0.0f, -0.0f, -0.5f);
}

TriangleSurface::TriangleSurface(const std::string &filename)
{
    std::ifstream inn(filename);
    if (!inn.is_open())
        return;
    // read input from math part of compulsory
    int n;
    Vertex v;
    inn >> n;
    for (auto i=0; i<n; i++)
    {
        inn >> v;
        mVertices.push_back(v);
        //qDebug() << v.x << v.y << v.z;
    }
    inn.close();
}
