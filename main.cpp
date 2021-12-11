#include <iostream>
#include "heap.cpp"
#include "set.cpp"
#include "graph.cpp"
#include "kruskal.cpp"
#include "prim.cpp"

int main() {
    Graph graph(100, 0.6);
//    graph.print_graph();
    Kruskal<int> kruskal_min_tree(graph);
    kruskal_min_tree.spanning_tree_search();
    kruskal_min_tree.print_min_spanning_tree_edges();

    Prim<int> prim_min_tree(graph);
    prim_min_tree.spanning_tree_search();
    prim_min_tree.print_min_spanning_tree_edges();
    return 0;
}
