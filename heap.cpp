//
// Created by psmolnik on 12/9/2021.
//
#include <iostream>
#include "stdlib.h"
#include <limits>
#include <vector>

using namespace std;

template<typename T>
class Heap {
protected:
    vector<std::pair<std::pair<size_t, size_t>, T> > keys;
    size_t d;
    size_t n;
    void tr(const size_t i, const size_t j);
    void make_heap();
    void emersion(size_t i);
    void diving(size_t i);
public:
    Heap(const vector<std::pair<std::pair<size_t, size_t>, T> >& keys_, const size_t d_);
    Heap(){};
    void init(const vector<std::pair<std::pair<size_t, size_t>, T> >& keys_, const size_t d_);
    void print_heap() const {
        for(size_t i = 0; i < n; i++)
            std::cout << keys[i].second << " ";
        std::cout << std::endl;
    }
    size_t find_min_child(size_t i) const;
    void insert_key(std::pair<std::pair<size_t, size_t>, T> key);
    void delete_key(size_t i);
    std::pair<std::pair<size_t, size_t>, T> find_min() const;
    void delete_min();
    size_t get_size() const {
        return n;
    }
};

template<typename T>
Heap<T>:: Heap(const vector<std::pair<std::pair<size_t, size_t>, T> >& keys_,
               const size_t d_) {
    keys = keys_;
    d = d_;
    n = keys.size();
    make_heap();
}

template<typename T>
void Heap<T>::init(const vector<std::pair<std::pair<size_t, size_t>, T> >& keys_,
                   const size_t d_) {
    keys = keys_;
    d = d_;
    n = keys.size();
    make_heap();
}

template<typename T>
void Heap<T>::tr(const size_t i, const size_t j) {
    std::swap(keys[i], keys[j]);
}

template<typename T>
void Heap<T>::emersion(size_t i) {
    while (i > 0){
        size_t parent = div(int(i - 1), int(d)).quot;
        if (keys[parent].second > keys[i].second){
            tr(i, parent);
            i = parent;
        }
        else
            return;
    }
    return;
}

template<typename T>
size_t Heap<T>::find_min_child(size_t i) const {
    size_t min_child = 0;
    size_t first = i * d + 1;
    if (first > n - 1)
        return min_child;
    size_t last = i * d + d;
    if (last > n - 1)
        last = n - 1;
    T min_key = std::numeric_limits<T>::max();
    for (int j = first; j <= last; j++){
        if (keys[j].second < min_key) {
            min_key = keys[j].second;
            min_child = j;
        }
    }
    return min_child;
}

template<typename T>
void Heap<T>::diving(size_t i) {
    while (1) {
        size_t j = find_min_child(i);
        if (j == 0)
            return;
        if (keys[i].second > keys[j].second) {
            tr(i, j);
            i = j;
        } else
            return;
    }
}

template<typename T>
void Heap<T>::insert_key(std::pair<std::pair<size_t, size_t>, T> key) {
    keys.push_back(key);
    emersion(n);
    n += 1;
    return;
}

template<typename T>
void Heap<T>::delete_key(size_t i) {
    keys[i] = keys[n -1];
    keys.resize(n - 1);
    n = n - 1;
    if ((i != 0) &&
        (keys[i].second < keys[div(int(i - 1), int(d)).quot].second))
        emersion(i);
    else
        diving(i);
    return;
}

template<typename T>
std::pair<std::pair<size_t, size_t>, T> Heap<T>::find_min() const {
    if (n > 0)
        return keys[0];
    else return std::make_pair(std::make_pair(0, 0), 0);
//    else return std::numeric_limits<T>::max();
}

template<typename T>
void Heap<T>::delete_min() {
    keys[0] = keys[n - 1];
    keys.resize(n - 1);
    n = n - 1;
    diving(0);
    return;
}

template<typename T>
void Heap<T>::make_heap() {
    for(int i = n - 1; i >= 0; i--){
        diving(i);
    }
    return;
}
