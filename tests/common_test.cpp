#include <iostream>
#include "../includes/common.h"

using namespace std;

void test_check() {
    string c = JNGEN_SWITCH_CHECKER("a", "b", "ccccccc", "dddddddd", "e", "f");
    cout << c << endl;

    // JNGEN_CHECK1(jngen::Exception, 1 == 2);
    // JNGEN_CHECK2(jngen::Exception, 1 == 2, "1 is not equal 2");

    CHECK(1 == 2);
    CHECK(1 == 2, "1 is not equal 2");
    // CHECK("a", "b", "c", 1 == 2, "1 is not equal 2");
}

void test_format() {
    string s = format("length is %d\n", 2);
    ostringstream os; os << s;
    CHECK(os.str() == "length is 2\n");
}

void test_timer() {
    ContextTimer ct("timer");
    for (int i = 1; i < (int)1e9; ++i) {}
}

void test_dist() {
    // Stupid test.
    int x = 1;
    auto f = [&] () {
        int r = x + 1;
        x = r;
        return r;
    };

    auto mp = distribution(100, f);
    for (auto it : mp) {
        cout << it.first << " " << it.second << endl;
    }
}

int main() {
    // test_format();
    // test_timer();
    test_dist();
    return 0;
}

