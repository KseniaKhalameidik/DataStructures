#include "heap.h"
#include <vector>
#include <iostream>

heap::heap(const std::vector<int> &array) : tree(array) {
    for (int j = tree.size() / 2; j >= 0; j--) {
        sift_down(j);
    }
}

void heap::top() {
    std::cout << tree[0];
}

void heap::push(int num) {
    tree.push_back(num);
    sift_up(tree.size() - 1);
}

void heap::pop() {
    if (tree.empty()) {
        return;
    }

    std::swap(tree[0], tree.back());
    tree.pop_back();
    sift_down(0);
}

void heap::sift_up(int i) {
    if (i == 0) {
        return;
    }
    if (tree[(i - 1) / 2] < tree[i]) {
        std::swap(tree[i], tree[(i - 1) / 2]);
        sift_up((i - 1) / 2);
    }
}

void heap::sift_down(int i) {
    int left, right, max;
    for (;;) {
        left = 2 * i + 1;
        right = 2 * i + 2;
        max = i;

        if (left < tree.size() && left > max) {
            max = left;
        }
        if (right < tree.size() && right > max) {
            max = right;
        }
        if (max == i) {
            break;
        }
        std::swap(tree[i], tree[max]);
        i = max;
    }
}
