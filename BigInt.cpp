#include "list.hpp"
#include <cmath>


class BigInt {
public:
    List data_;
    BigInt operator=(int x) {
       BigInt res;
        int i{1};
        int osn = 10;
        while (x /  osn != 0) {
            data_.insert(x % osn, 0);
            i++;
            osn *= 10;
        }
        return res;
    }
};