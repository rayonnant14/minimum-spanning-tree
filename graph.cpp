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
    Graph(const vector<vector<int> >& adj_matrix_);
    Graph(const int nodes_num, const double density);
    void print_graph() const;
protected:
    void generate_random_graph(const double density);
private:
    vector<vector<int> > adj_matrix;
    size_t nodes_num;
};

Graph::Graph(const vector<vector<int> >& adj_matrix_) {
    adj_matrix = adj_matrix_;
    nodes_num = adj_matrix_.size();
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
            int weight = int(gen() % 100);
            if (pd(gen)) {
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