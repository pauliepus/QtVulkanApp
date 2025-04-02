#include <iostream>
#include <vector>
#include <Eigen/Dense>

struct Point {
    double x, y;
};

void quadraticLeastSquares(const std::vector<Point>& points, double& a, double& b, double& c) {
    int n = points.size();
    double Sx = 0, Sy = 0, Sxx = 0, Sxxx = 0, Sxxxx = 0, Sxy = 0, Sxxy = 0;

    for (const auto& p : points) {
        Sx += p.x;
        Sy += p.y;
        Sxx += p.x * p.x;
        Sxxx += p.x * p.x * p.x;
        Sxxxx += p.x * p.x * p.x * p.x;
        Sxy += p.x * p.y;
        Sxxy += p.x * p.x * p.y;
    }

    // Solve using Eigen for Ax = B (Matrix Form)
    Eigen::Matrix3d A;
    Eigen::Vector3d B, X;

    A << Sxxxx, Sxxx, Sxx,
        Sxxx, Sxx, Sx,
        Sxx, Sx, n;

    B << Sxxy, Sxy, Sy;

    X = A.colPivHouseholderQr().solve(B);
    a = X(0);
    b = X(1);
    c = X(2);
}

int main() {
    std::vector<Point> points = { {1, 2}, {2, 2.5}, {3, 3.5}, {4, 5.0}, {5, 6.8} };

    double a, b, c;
    quadraticLeastSquares(points, a, b, c);

    std::cout << "Best fit curve: y = " << a << "x^2 + " << b << "x + " << c << std::endl;
    return 0;
}
