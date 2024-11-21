#include <iostream>
int main()
{
    int res{1};
    int n{};
    std::cin >> n;
    int matA[n][n], matB[n][n], matAB[n][n];
    for (int y{}; y < n; y++) {
        for (int x{}; x < n; x++) {
            matA[y][x] = 1 + rand() % 10;
            matB[y][x] = 1 + rand() % 10;
        }
    }
    for (int y{}; y < n; y++) {
        for (int x{}; x < n; x++) {
            matAB[y][x] = matA[y][x] + matB[y][x];
        }
    }
    for (int y{}; y < n; y++) {
        for (int x{}; x < n; x++) {
            if (x == n - 1) {std::cout << matAB[y][x] << "\n";}
            else {std::cout << matAB[y][x] << "\t";}
        }
    }
    for (int y{}; y < n; y++) {
        for (int x{}; x < n; x++) {
            if (x == y) {
                res *= matAB[y][x];
                res *= matAB[y][n - 1 - x];
            }
        }
    }
    std::cout << "res" << "\t" << res;
    return 0;
}
