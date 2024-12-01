#include <iostream>

int maxnum(int mat[][3]) {
    int maximum{};
    for (int y{}; y < 3; y++) {
        for (int x{}; x < 3; x++) {
            if (mat[y][x] > maximum) {maximum = mat[y][x];}
        }
    }
    return maximum;
}
int main()
{
    int mat1[3][3], mat2[3][3];
    for (int y{}; y < 3; y++) {
        for (int x{}; x < 3; x++) {
            mat1[y][x] = 1 + rand() % 10;
            mat2[y][x] = 1 + rand() % 10;
        }
    }
    std::cout << maxnum(mat1) << "\t" << maxnum(mat2);
    return 0;
}
