#include <vector>
#include <string>
#include <graphviz/gvc.h>
#include <graphviz/cgraph.h>

#include "../includes/array.h"
#include "../includes/generic_graph.h"

namespace jngen {
// A general class for drawing a graph.
class Graphviz {
public:
    Graphviz() {}
    explicit Graphviz(std::shared_ptr<GenericGraph>g, std::string name)
        : g_(g), name_(name) {}

    // Set up a graphviz context.
    void create_context();

    // Create a graphviz graph.
    void create_graph();

    // Draw a graph.
    void draw_graph();

private:
   GVC_t *gvc_;
   std::shared_ptr<GenericGraph> g_;
   Agraph_t *gv_;
   std::vector<Agnode_t*> gvc_nodes_;
   std::vector<Agedge_t*> gvc_edges_;
   // Layout engine: default `dot`
   // int layout_engine_{0};
   // // Save type for output: default `pdf`
   // int save_type_{0};
   // string save name
   std::string name_;
};

#ifndef JNGEN_DECLARE_ONLY

void Graphviz::draw_graph() {
    this->create_context();

    this->create_graph();

    // TODO(landcold7): make this cnfigable.
    gvLayout (gvc_, gv_, "sfdp");
    name_ += ".pdf";
    gvRenderFilename (gvc_, gv_, "pdf", name_.c_str());

    gvFreeLayout(gvc_, gv_);
    agclose (gv_);
    gvFreeContext(gvc_);
}

void Graphviz::create_graph() {

    gv_ = agopen(const_cast<char*>("g"), Agundirected, 0);

    // TODO(landcold7): speed up for drawing a large graph.
    // agsafeset(gv_, const_cast<char*>("overlap"),
    //           const_cast<char*>("true"),
    //           const_cast<char*>(""));

    for (int i = 0; i < g_->n(); ++i) {
        // Node's name starting from zero.
        // TODO (landcold7): make it configable.
        Agnode_t *n = agnode(gv_, (char*)std::to_string(i).c_str(), 1);
        gvc_nodes_.push_back(n);
    }

    Arrayp edges = g_->edges();
    auto edges_weight = g_->edgesWeight();
    for (int i = 0; i < g_->m(); ++i) {
        int u = edges[i].first;
        int v = edges[i].second;
        Agedge_t *e = agedge(gv_, gvc_nodes_[u], gvc_nodes_[v], 0, 1);
        gvc_edges_.push_back(e);
        // If this edge has a weight on it.
        if (edges_weight.size()) {
            int w = edges_weight[i];
            agsafeset(e, const_cast<char*>("label"),
                      (char*)std::to_string(w).c_str(),
                      const_cast<char*>(""));
        }
    }


}

void Graphviz::create_context() {
    gvc_ = gvContext();
}

#endif

} // namespace jngen

using jngen::Graphviz;

