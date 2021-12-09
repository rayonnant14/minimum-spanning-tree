#include <iostream>
#include "heap.cpp"

int main() {
    vector<double> keys{10.1, 5.1, 2.4, 7.0, 2.4, 2.3};
    Heap<double> heap(keys, 2);
    heap.print_heap();
    return 0;
}
