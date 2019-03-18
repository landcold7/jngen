#include <iostream>
#include <sstream>
#include <cassert>
#include "../includes/printers.h"

template<typename T>
void checkOutput(const T& t, const std::string& s) {
    std::ostringstream ss;
    ss << t;
    assert(ss.str() == s);
}

void test_repr() {
    setMod().reset();

    std::vector<int> x{0, 1, 2};
    checkOutput(repr(x), "0 1 2");
    checkOutput(repr(x).add1(), "1 2 3");

    std::pair<double, long long> y(0.123456, 31415);

    checkOutput(repr(y), "0.123456 31415");
    checkOutput(repr(y).add1(), "0.123456 31416");
}

class T : public jngen::ReprProxy<T> {
    friend std::ostream operator<< (std::ostream &os, T &t) {
        return std::cout << t.a << t.t << std::endl;
    }

    std::vector<int> a = {1, 2, 3};
    int t = 2;
};

void test_class() {
    T t;
    std::cout << t;
}

int main() {
    test_repr();
    test_class();
    return 0;
}
