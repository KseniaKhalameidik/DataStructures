#pragma once

#include <vector>

class heap {
    std::vector<int> tree;

    void sift_up(int i);

    void sift_down(int i);

public:
    heap(const std::vector<int> &array) : tree(array) {
        for (int j = tree.size() / 2; j >= 0; j--) {
            sift_down(j);
        }
    }
};
