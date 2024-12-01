#include "list.hpp"
#include <cmath>


class BigInt {
public:
    List get_data() const {
        return this->data_;
    }
    
    BigInt (const int& val = 0) {
        data_ = parse(val);
    }

    BigInt& operator=(const int& val) {
        if (data_.len() != 0) {this->data_.del();}
        data_ = parse(val);
        return *this;
    }

private:
    List data_;
    
    List parse (const int& val) const {
        List res;
        int x = val;
        int osn = 10;
        if (x < osn) {res.insert(x);}
        while (x >= osn / 10) {
            res.insert(x % osn);
            x /= osn;
        }
        return res;
    }
};