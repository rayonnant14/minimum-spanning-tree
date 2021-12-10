//
// Created by psmolnik on 12/10/2021.
//

#include <iostream>
#include "stdlib.h"
#include <vector>

using namespace std;

class Set{
public:
    Set(const size_t set_size);
    Set(){};
    void init(const size_t set_size);
    void create(const size_t x);
    void merge(const size_t x, const size_t y);
    size_t find(size_t x);
protected:
    vector<size_t> p;
    vector<size_t> r;
};

Set::Set(const size_t set_size) {
    p.resize(set_size, 0);
    r.resize(set_size, 0);
//    for (size_t i = 0; i < set_size; i++)
//        create(i);
}

void Set::init(const size_t set_size) {
    p.resize(set_size, 0);
    r.resize(set_size, 0);
    for (size_t i = 0; i < set_size; i++)
        create(i);
}

void Set::create(const size_t x) {
    p[x] = x;
    r[x] = 0;
    return;
}

void Set::merge(const size_t x, const size_t y) {
    if (r[x] < r[y]) {
        p[x] = y;
    }
    else if (r[x] > r[y]) {
        p[y] = x;
    }
    else {
        p[x] = y;
        r[y] += 1;
    }
    return;
}

size_t Set::find(size_t x) {
    size_t z = x;
    while (p[x] != x) {
        x = p[x];
    }
    size_t y = x;
    while (p[z] != z) {
        size_t z_ = z;
        z = p[z];
        p[z_] = y;
    }
    return y;
}