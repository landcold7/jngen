#include <iostream>
#include "../includes/hash.h"

using namespace std;

void test_int() {
    int a = 1;
    hash<int> h;
    uint64_t v = h(a);
    cout << v << endl;
}

void test_vector() {
    vector<int> a = {1, 2, 3};
    hash<vector<int>> h;
    uint64_t v = h(a);
    cout << v << endl;
}

void test_float() {
    float a = 1.234;
    hash<float> h;
    uint64_t v = h(a);
    cout << v << endl;
}

int main() {
    test_int();
    test_vector();
    test_float();
    return 0;
}
