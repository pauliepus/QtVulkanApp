// Dag Nylund, Universitetet i Innlandet
// Matematikk III 2025

#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include "QVector2D"
#include "QVector3D"

struct  Vertex {
    float x;
    float y;
    float z;
    float r;
    float g;
    float b;
    float u;
    float v;
    Vertex() = default;
    Vertex(QVector3D pos, QVector3D normal, QVector2D uv);
    Vertex(float x, float y, float z, float r, float g, float b, float u, float v)
        : x(x), y(y), z(z), r(r), g(g), b(b), u(u), v(v) {}

    //! Overloaded ostream operator which writes all vertex data on an open textfile stream
    friend std::ostream& operator<< (std::ostream&, const Vertex&);

    //! Overloaded ostream operator which reads all vertex data from an open textfile stream
    friend std::istream& operator>> (std::istream&, Vertex&);
};

#endif // VERTEX_H
