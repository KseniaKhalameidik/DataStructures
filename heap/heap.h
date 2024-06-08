#pragma once

#include <vector>

class heap {
    std::vector<int> tree;

    void sift_up(int i);

    void sift_down(int i);

public:
    heap(const std::vector<int> &array);

    void top();

    void push(int num);

    void pop();
};
