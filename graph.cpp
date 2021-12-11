//
// Created by psmolnik on 12/10/2021.
//
#include <iostream>
#include <vector>
#include <random>

using namespace std;

static std::random_device rd;
static std::mt19937 gen(rd());

class Graph {
public:
    Graph(const vector<vector<int> >& adj_matrix_, const size_t edges_num_);
    Graph(const int nodes_num, const double density);
    Graph(){};
    void print_graph() const;
    size_t get_nodes_num() const {
        return nodes_num;
    }
    size_t get_edges_num() const {
        return edges_num;
    }
    vector<vector<int> > get_adj_matrix() const {
        return adj_matrix;
    }
    int operator()(const size_t i, const size_t j);

protected:
    void generate_random_graph(const double density);
private:
    vector<vector<int> > adj_matrix;
    size_t nodes_num = 0;
    size_t edges_num = 0;
};

Graph::Graph(const vector<vector<int> >& adj_matrix_, const size_t edges_num_) {
    adj_matrix = adj_matrix_;
    nodes_num = adj_matrix_.size();
    edges_num = edges_num_;
}

Graph::Graph(const int nodes_num_, const double density) {
    nodes_num = nodes_num_;
    adj_matrix.resize(nodes_num);
    for (size_t i = 0; i < nodes_num; i++)
        adj_matrix[i].resize(nodes_num);
    generate_random_graph(density);
}

void Graph::generate_random_graph(const double density) {
    bernoulli_distribution pd(density);
    for (size_t i = 0; i < nodes_num; i++)
        for (size_t j = 0; j < nodes_num; j++) {
            if (i == j) {
                adj_matrix[i][j] = -1;
                continue;
            }
            int weight = int(1 + gen() % 100);
            if (pd(gen)) {
                edges_num++;
                adj_matrix[i][j] = weight;
                adj_matrix[j][i] = weight;
            }
            else {
                adj_matrix[i][j] = -1;
                adj_matrix[j][i] = -1;
            }
        }
    return;
}

void Graph::print_graph() const {
    for (size_t i = 0; i < nodes_num; i++) {
        for (size_t j = 0; j < nodes_num; j++) {
            std::cout << adj_matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return;
}

int Graph::operator()(const size_t i, const size_t j) {
    return adj_matrix[i][j];
}