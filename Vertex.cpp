// Dag Nylund, Universitetet i Innlandet
// Matematikk III 2025

#include "Vertex.h"
#include "vector"

std::ostream& operator<< (std::ostream& os, const Vertex& v) {
    os << std::fixed;
    os << "(" << v.x << ", " << v.y << ", " << v.z << ") ";
    os << "(" << v.r << ", " << v.g << ", " << v.b << ") ";
    os << "(" << v.u << ", " << v.v << ") ";
    return os;
}
std::istream& operator>> (std::istream& is, Vertex& v) {
    // Trenger fire temporære variabler som kun skal lese inn parenteser og komma
    char dum, dum2, dum3, dum4;
    is >> dum >> v.x >> dum2 >> v.y >> dum3 >> v.z >> dum4;
    is >> dum >> v.r >> dum2 >> v.g >> dum3 >> v.b >> dum4;
    is >> dum >> v.u >> dum2 >> v.v >> dum3;
    return is;
}

std::vector<Vertex> cubeVertices = {
    // Front face
    { -0.5f, -0.5f,  0.5f,  1.0f, 0.0f, 0.0f,  0.0f, 0.0f },
    {  0.5f, -0.5f,  0.5f,  0.0f, 1.0f, 0.0f,  1.0f, 0.0f },
    {  0.5f,  0.5f,  0.5f,  0.0f, 0.0f, 1.0f,  1.0f, 1.0f },
    { -0.5f,  0.5f,  0.5f,  1.0f, 1.0f, 1.0f,  0.0f, 1.0f },

    // Back face
    { -0.5f, -0.5f, -0.5f,  1.0f, 0.0f, 1.0f,  0.0f, 0.0f },
    {  0.5f, -0.5f, -0.5f,  0.0f, 1.0f, 1.0f,  1.0f, 0.0f },
    {  0.5f,  0.5f, -0.5f,  1.0f, 1.0f, 0.0f,  1.0f, 1.0f },
    { -0.5f,  0.5f, -0.5f,  0.5f, 0.5f, 0.5f,  0.0f, 1.0f }
};

std::vector<uint16_t> cubeIndices = {
    0, 1, 2, 2, 3, 0,  // Front
    4, 5, 6, 6, 7, 4,  // Back
    0, 1, 5, 5, 4, 0,  // Bottom
    2, 3, 7, 7, 6, 2,  // Top
    0, 3, 7, 7, 4, 0,  // Left
    1, 2, 6, 6, 5, 1   // Right
};
