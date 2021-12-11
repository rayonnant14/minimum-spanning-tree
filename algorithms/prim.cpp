//
// Created by psmolnik on 12/10/2021.
//
template<typename T>
class Prim {
public:
    Prim(const Graph& G_);
    void spanning_tree_search();
    void print_min_spanning_tree_edges() const {
        T weight = 0;
        for(auto edge:min_spanning_tree_edges)
        {
//            std::cout << "edge (" << edge.first.first << ", " << edge.first.second
//                      << "), weight " << edge.second << std::endl;
            weight += edge.second;
        }
        std::cout << "Total tree weight " << weight << std::endl;
    }
protected:
    Graph G;
    Heap<T> heap;
    std::vector<std::pair<std::pair<size_t, size_t>, T> > edges;
    std::vector<std::pair<std::pair<size_t, size_t>, T> > min_spanning_tree_edges;
    std::vector<bool> labels;
};

template<typename T>
Prim<T>::Prim(const Graph& G_) {
    G = G_;
    edges.resize(G.get_nodes_num());
    labels.resize(G.get_nodes_num(), false);
}

template<typename T>
void Prim<T>::spanning_tree_search() {
    labels[0] = true;
    edges[0].first = std::make_pair(0, 0);
    edges[0].second = std::numeric_limits<T>::max();
    for(size_t i = 1; i < G.get_nodes_num(); i++) {
        if (G(0, i) != -1) {
            edges[i].first = std::make_pair(0, i);
            edges[i].second = G(0, i);
        }
        else {
            edges[i].first = std::make_pair(0, i);
            edges[i].second = std::numeric_limits<T>::max();
        }
    }
    heap.init(edges,2);

    while (min_spanning_tree_edges.size() != G.get_nodes_num() - 1) {
        std::pair<std::pair<size_t, size_t>, T> edge = heap.find_min();
        heap.delete_min();
        min_spanning_tree_edges.push_back(edge);
        size_t label_node = edge.first.second;
        labels[label_node] = true;
        for(size_t i = 0; i < heap.get_size(); i++) {
            std::pair<std::pair<size_t, size_t>, T> cur_key = heap[i];
            size_t cur_node = cur_key.first.second;
            T cur_weight = cur_key.second;
            if ((G(label_node, cur_node) != -1) &&
                (labels[cur_node] == false)) {
                if (G(label_node, cur_node) < cur_weight) {
                    std::pair<std::pair<size_t, size_t>, T> upt_cur_key = std::make_pair(std::make_pair(label_node, cur_node),
                                                                                           G(label_node, cur_node));

                    heap.decrease_key(i, upt_cur_key);
                }
            }
        }
    }
    return;
}
