#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
using namespace std;
int main()
{
    double f;
    int x0, xn, h;
    cin >> x0 >> xn >> h;
    cout << "x" << "\t" << "f" << "\n";
    for (x0; x0 < xn; x0 + h) {
        if (x0 < 3) {double f = 2*x0 + tan(x0) + sqrt(log(abs(x0 - 3)));}
        if (x0 == 3) {double f = pow((pow(x0, 2) - 3), 2) - sin(2) * x0;}
        if (x0 > 3) {double f = (x0 + 3) - cos(M_PI) * x0;}
        cout << x0 << "\t" << f;
    }
    return 0;
}
