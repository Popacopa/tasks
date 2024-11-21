#include <math.h>
#include <iostream>

int main()
{
    int d[3];
    for (int i{}; i < 3; i++) {
        std::cin >> d[i];
    }
    if (d[0] + d[1] <= d[2] || d[1] + d[2] <= d[0] || d[2] + d[0] <= d[1]) {
        std::cout << "triangle is not exist";
    } else {
        float a = (pow(d[0], 2) - pow(d[1], 2) - pow(d[2], 2)) / -2*d[1]*d[2];
        float b = (pow(d[1], 2) - pow(d[0], 2) - pow(d[2], 2)) / -2*d[0]*d[2];
        float c = (pow(d[2], 2) - pow(d[0], 2) - pow(d[1], 2)) / -2*d[0]*d[1];
        if (a == 0 || b == 0 || c == 0) {std::cout << "треугольник прямоугольный";}
        else if (a < 0 || b < 0 || c < 0) {std::cout << "треугольник тупоугольный";}
        else if (a > 0 && b > 0 && c > 0) {std::cout << "треугольник остроугольный";} 
    } 
}
