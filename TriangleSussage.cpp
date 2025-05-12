#include "TriangleSussage.h"
#include <fstream>
#include <QDebug>

TriangleSussage::TriangleSussage() : VisualObject()
{

    constructPlane();

    mMatrix.scale(0.5f);
    mMatrix.translate(0.5f, 0.1f, 0.1f);

}

TriangleSussage::TriangleSussage(const std::string &filename)
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

void TriangleSussage::constructPlane()
{

    float dx=2.0;
    float dy=2.0;
    mVertices.clear();
    for (float y=-2.0; y<2.0; y+=dy)
    {
        for (float x=-3.0; x<3.0; x+=dx)
        {
            float x0=x;
            float y0=y;
            float x1=x0+dx;
            float y1=y0+dy;
            mVertices.push_back(Vertex{x0, y0, 0, 0, 0, 1, 0, 0});
            mVertices.push_back(Vertex{x1, y0, 0, 0, 0, 1, 0, 0});
            mVertices.push_back(Vertex{x0, y1, 0, 0, 0, 1, 0, 0});
            mVertices.push_back(Vertex{x0, y1, 0, 0, 0, 1, 0, 0});
            mVertices.push_back(Vertex{x1, y0, 0, 0, 0, 1, 0, 0});
            mVertices.push_back(Vertex{x1, y1, 0, 0, 0, 1, 0, 0});
        }
    }
}
