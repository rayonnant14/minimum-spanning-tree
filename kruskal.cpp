//
// Created by psmolnik on 12/10/2021.
//
#include <iostream>
#include <vector>
#include <random>
#include "graph.cpp"
#include "set.cpp"
#include "heap.cpp"

class Kruskal {
public:
    Kruskal(const Graph& G_);
    void spanning_tree_search();
    void print_min_spanning_tree_edges() const {
        for(auto edge:min_spanning_tree_edges)
        {
            std::cout << "edge (" << edge.first.first << ", " << edge.first.second
                      << "), weight " << edge.second << std::endl;
        }
    }
protected:
    Graph G;
    Set S;
    Heap<int> heap;
    std::vector<std::pair<std::pair<size_t, size_t>, int> > edges;
    void create_edges_from_adj_matrix(const Graph& G);
    std::vector<std::pair<std::pair<size_t, size_t>, int> > min_spanning_tree_edges;
};

Kruskal::Kruskal(const Graph& G_) {
    G = G_;
    S.init(G.get_nodes_num());
    create_edges_from_adj_matrix(G);
    heap.init(edges, 2);
}

void Kruskal::create_edges_from_adj_matrix(const Graph& G) {
    vector<vector<int> > adj_matrix = G.get_adj_matrix();
    for (size_t i = 0; i < G.get_nodes_num(); i++)
        for (size_t j = i + 1; j < G.get_nodes_num(); j++) {
            if (adj_matrix[i][j] != -1)
                edges.push_back(std::make_pair(std::make_pair(i, j), adj_matrix[i][j]));
        }
}

void Kruskal::spanning_tree_search() {
    do {
        std::pair<std::pair<size_t, size_t>, int> min_edge = heap.find_min();
        heap.delete_min();
        size_t x = S.find(min_edge.first.first);
        size_t y = S.find(min_edge.first.second);
        if (x != y) {
            min_spanning_tree_edges.push_back(min_edge);
            S.merge(x, y);
        }
    } while ((heap.get_size() > 0) && (min_spanning_tree_edges.size() < G.get_nodes_num()));
    return;
}
