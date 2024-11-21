#include <iostream>
#include <string>

int main()
{
    std::string a{}, b{};
    std::cout << "строка A: "; std::cin >> a;
    std::cout << "строка B: "; std::cin >> b;
    for (int i{}; i < size(b); i++) {
        if (a.find(b[i]) != std::string::npos) {
            a.erase(a.find(b[i]), 1);
        }
    }
    std::cout << a;
    return 0;
}