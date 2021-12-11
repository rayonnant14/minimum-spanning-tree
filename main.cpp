#include <iostream>
#include "heap.cpp"
#include "set.cpp"
#include "graph.cpp"
#include "kruskal.cpp"
#include "prim.cpp"

int main() {
//    vector<double> keys{10.1, 5.1, 2.4, 7.0, 2.4, 2.3};
//    Heap<double> heap(keys, 2);
//    heap.print_heap();
    Graph graph(10000, 0.6);
//    graph.print_graph();
    Kruskal kruskal_min_tree(graph);
    kruskal_min_tree.spanning_tree_search();
    kruskal_min_tree.print_min_spanning_tree_edges();

    Prim prim_min_tree(graph);
    prim_min_tree.spanning_tree_search();
    prim_min_tree.print_min_spanning_tree_edges();
    return 0;
}
