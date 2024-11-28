#include "list.hpp"
#include "BigInt.cpp"
int main()
{
    try {
        List arr;
        arr.append(1);
        arr.print();
        return 0;
    } catch (...) {
        std::cout << "except!";
        return -1;
    }
}
