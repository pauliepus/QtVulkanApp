#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Vertex.h"

struct Point{

    double x;
    double y;

};

std::vector<std::vector<std::string>> sPoints;  //vector of vectors of points as strings
std::vector<std::string> tempVector;            // temporary vector to store single strings of points
std::string tempString;
std::string::size_type SZ;

// Function to compute linear least squares
void linearLeastSquares(const std::vector<Point>& points, double& Beta1, double& Beta0) {
    int n = points.size();
    double Sx = 0, Sy = 0, Sxx = 0, Sxy = 0;

    for (const auto& p : points) {
        Sx += p.x;
        Sy += p.y;
        Sxx += p.x * p.x;
        Sxy += p.x * p.y;
    }

    Beta1 = ((n * Sxy) - (Sx * Sy)) / ((n * Sxx) - (Sx * Sx));
    Beta0 = ((Sy - Beta1 * Sx) / n);
}

std::vector<Point> ReadFromFile(const std::string& filename)
{
    std::vector<Point> points;
    std::vector<Vertex> curveVertices;

    double a, b;

    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cerr << "Failed to open file: " << filename << std::endl;
        throw;
    }

    while (file.peek() != EOF)
    {
        Point temp;
        file >> temp.x >> temp.y;
        points.emplace_back(temp);

        // Convert Point to Vertex
        Vertex v;
        v.x = temp.x;
        v.y = temp.y;
        v.z = 0.0f; // Or some logic here if z is needed
        curveVertices.push_back(v);
    }

    file.close();

    linearLeastSquares(points, a, b);
    std::cout << "Best fit line: y = " << a << "x + " << b << std::endl;

    for (const auto& p : points)
    {
        std::cout << p.x << ", " << p.y << std::endl;
    }

    std::cout << points.size() << std::endl;

    return points;
}


int main() {
    /* Original Vector for Points */
    //std::vector<Point> points = {{1, 2}, {2, 2.8}, {3, 3.6}, {4, 4.5}, {5, 5.1}};

    ReadFromFile("C:/CurrentProject/QtVulkanApp/game_tech_least_squares_mixed.csv");

    return 0;
}
