#include "../includes/jngen.h"
#include <bits/stdc++.h>
using namespace std;

int main() {
    int max_n = 1000, max_weight = 100000, nt = 1;
    // cout << nt << endl;
    cout << "graph {\n";
    for (int t = 0; t < nt; ++t) {
        int n = rnd.next(2, max_n);
        int m = rnd.next(n - 1, n * (n - 1) / 2);
        auto g = Graph::random(n, m).connected().g();
        g.setEdgeWeights(Array::random(m, 1, max_weight));
        // cout << g.printN().printM() << endl;

        Arrayp edge = g.edges();
        WeightArray weights = g.edgesWeight();

        for (int i = 0; i < m; ++i) {
            int w = weights[i];
            cout << edge[i].first
                 << " -- "
                 << edge[i].second
                 << " [\"label\"=\""
                 << to_string(w)
                 << "\"]\n";
        }

        // Graphviz gv(make_shared<Graph>(g), "g");
        // gv.draw_graph();
    }
    cout << "}\n";
}

