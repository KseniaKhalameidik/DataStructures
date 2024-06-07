#include "heap/tests.h"

void test_heap() {
    test_remove_from_empty();
    test_add_one_value_and_print();
    test_add_random_values_and_print();
    test_add_and_remove_random_values_and_print();
}
int main() {
    test_heap();

    return 0;
}
