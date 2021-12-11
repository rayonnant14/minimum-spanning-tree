#include "data_structures/heap.cpp"
#include "data_structures/set.cpp"
#include "data_structures/graph.cpp"
#include "algorithms/kruskal.cpp"
#include "algorithms/prim.cpp"

int main() {
    Graph graph(100, 0.6);
    Kruskal<int> kruskal_min_tree(graph);
    kruskal_min_tree.spanning_tree_search();
    kruskal_min_tree.print_min_spanning_tree_edges();

    Prim<int> prim_min_tree(graph);
    prim_min_tree.spanning_tree_search();
    prim_min_tree.print_min_spanning_tree_edges();
    return 0;
}
