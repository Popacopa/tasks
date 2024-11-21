

#include <iostream>
using namespace std;
int main(){}
void multiplication(int(&a1)[4][4], int(&b)[4][4], int(&c)[4][4], int row1, int col1, int col2) {
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            c[i][j] = 0;
            for (int k = 0; k < col1; k++){
                c[i][j] += a1[i][k] * b[k][j];
        
            }
        }
    }
}