#pragma once

#include "heap.h"
#include <iostream>
#include <random>
#include <algorithm>

void test_remove_from_empty() {
    heap h({});
    h.pop();
}

void test_add_one_value_and_print() {
    heap h({});
    int num;
    std::cin >> num;
    h.push(num);
    h.print();
    std::cout << std::endl;
}

void test_add_random_values_and_print() {
    heap h({});

    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, 21);

    int num = uniform_dist(e1);
    std::uniform_int_distribution<int> uniform_dist_elements(-50, 50);
    for (int i = 0; i < num; i++) {
        h.push(uniform_dist_elements(e1));
    }
    h.print();
    std::cout << std::endl;
}

void test_add_and_remove_random_values_and_print() {
    heap h({});

    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, 21);

    int num = uniform_dist(e1);
    std::vector<int> arr;
    std::uniform_int_distribution<int> uniform_dist_elements(-50, 50);
    for (int i = 0; i < num; i++) {
        int x = uniform_dist_elements(e1);

        h.push(x);
        arr.push_back(x);
    }
    h.print();
    std::cout << std::endl;

    for (int i = 0; i < num / 2; i++) {
        h.pop();
    }

    std::sort(arr.begin(), arr.end(), std::greater<int>());

    if (arr[num/2] == h.top()) {
        h.print();
        std::cout << std::endl;
    }
    else {
        std::cout << "failed: test_add_and_remove_random_values_and_print";
    }
}
