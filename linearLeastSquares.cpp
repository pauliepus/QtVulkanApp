#include <iostream>
#include <vector>

struct Point {
    double x, y;
};

// Function to compute linear least squares
void linearLeastSquares(const std::vector<Point>& points, double& Beta0, double& Beta1) {
    int n = points.size();
    double Sx = 0, Sy = 0, Sxx = 0, Sxy = 0; //sxy is sum of x*y

    //sx is sum of ALL x values, Sy, is sum of all Y values, Sxx should be

    for (const auto& p : points) {
        Sx += p.x;

        // Compute all necessary sum

    }

    // Beta1 = // complete the code
    // Beta0 = // complete the code
}
int main() {
    std::vector<Point> points = {{1, 2}, {2, 2.8}, {3, 3.6}, {4, 4.5}, {5, 5.1}};
    
    double a, b;
    linearLeastSquares(points, a, b);

    std::cout << "Best fit line: y = " << a << "x + " << b << std::endl;
    return 0;
}
