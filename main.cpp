#include "data_structures/heap.cpp"
#include "data_structures/set.cpp"
#include "data_structures/graph.cpp"
#include "algorithms/kruskal.cpp"
#include "algorithms/prim.cpp"
#include <chrono>
#include <fstream>

void benchmark() {
    std::ofstream outfile_kruskal("C:\\Users\\psmolnik\\OneDrive - Intel Corporation\\Documents\\minimum-spanning-tree\\data\\kruskal_0_9.txt");
    std::ofstream outfile_prim("C:\\Users\\psmolnik\\OneDrive - Intel Corporation\\Documents\\minimum-spanning-tree\\data\\prim_0_9.txt");
    outfile_kruskal << "node_num microseconds" << std::endl;
    outfile_prim << "node_num microseconds" << std::endl;
    for (size_t nodes_num = 25; nodes_num <= 2000; nodes_num+=25) {
        Graph graph(nodes_num);
        Kruskal<int> kruskal_min_tree(graph);
        auto t1 = std::chrono::high_resolution_clock::now();
        kruskal_min_tree.spanning_tree_search();
        auto t2 = std::chrono::high_resolution_clock::now();
        double time_kruskal = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
        outfile_kruskal << nodes_num << " " << time_kruskal << std::endl;
        std::cout << "time_kruskal:" << time_kruskal << std::endl;

        Prim<int> prim_min_tree(graph);
        t1 = std::chrono::high_resolution_clock::now();
        prim_min_tree.spanning_tree_search();
        t2 = std::chrono::high_resolution_clock::now();
        double time_prim = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
        outfile_prim << nodes_num << " " << time_prim << std::endl;
        std::cout << "time_prim:" << time_prim << std::endl;
    }
    outfile_kruskal.close();
    outfile_prim.close();
    return;
}

int main() {
    benchmark();
    return 0;
}
