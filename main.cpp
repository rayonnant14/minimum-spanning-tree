#include <iostream>
#include "heap.cpp"
#include "graph.cpp"

int main() {
//    vector<double> keys{10.1, 5.1, 2.4, 7.0, 2.4, 2.3};
//    Heap<double> heap(keys, 2);
//    heap.print_heap();
    Graph graph(5, 0.8);
    graph.print_graph();
    return 0;
}
