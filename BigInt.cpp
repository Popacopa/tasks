#include "list.hpp"
#include <cmath>


class BigInt {
public:
    List data_;
    BigInt& operator=(const int& val) {
        int x = val;
        int osn = 10;
        while (x >= osn / 10) {
            data_.insert(x % osn, 0);
            x /= osn;
        }
        return *this;
    }
};