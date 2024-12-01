#include <iostream>

float maxel(float matrix[][3]) {
    float maximum{};
    for (int y{}; y < 3; y++) {
        for (int x{}; x < 3; x ++) {
            if (maximum < matrix[y][x]) {
                maximum = matrix[y][x];
            }
        }      
    }
    return maximum;
}

int main(int argc, char const *argv[])
{
    float matA[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    float matB[][3] = {{4, 17, 3}, {4, 32, 6}, {7, 1, 9}};
    std::cout << maxel(matB) << std::endl;
    std::cout << maxel(matA) << std::endl;
    return 0;
}
