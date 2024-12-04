#include <iostream>
#include <cmath>

int main()
{
    double x0, xn, h, s, n, u, e=1E-5;
    std::cin >> x0 >> xn >> h;
    std::cout << "x" << "\t" << "sum" << "\t" << "y" << "\n";
    for (x0; x0 < xn; x0 += h) {
        s = 0; u = 1; n = 0;
        while (abs(u) > e) {
            u = (sqrt(2*x0) / (n + 1)); // рекурентная формула
            s += u;
            n++;
        }
        double y = exp(-2 * x0);
        std::cout << x0 << "\t" << s << "\t" << y << std::endl;
    }
    return 0;
}
