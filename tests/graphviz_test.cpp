#include "../includes/jngen.h"
#include <bits/stdc++.h>
using namespace std;

int main() {
    int max_n = 4, max_weight = 100000, nt = 1;
    cout << nt << endl;
    for (int t = 0; t < nt; ++t) {
        int n = rnd.next(2, max_n);
        int m = rnd.next(n - 1, n * (n - 1) / 2);
        auto g = Graph::random(n, m).connected().g();
        g.setEdgeWeights(Array::random(m, 1, max_weight));
        cout << g.printN().printM() << endl;

        Graphviz gv(make_shared<Graph>(g), "g");
        gv.draw_graph();
    }
}

