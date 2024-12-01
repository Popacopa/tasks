#include <iostream>

int main()
{
    int arr[10]{};
    int sum = 0;
    for (int i = 0; i < 10; i++) {std::cin >> arr[i];}
    int marr = 0;
    for (int i = 0; i < 10; i++) {if (arr[i] > marr) {marr = i;};}
    for (int i = marr + 1; i < 10; i++) {sum += arr[i];}
    std::cout << sum;
    return 0;
}
