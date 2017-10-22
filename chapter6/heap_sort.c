#include <stdio.h>

int parent(int i) {
    return i / 2 - 1;
}

int left_child(int i) {
    return 2i + 1;
}

int right_child(int i) {
    return 2 * (i + 1);
}

int build_max_heap(int[], int);
int max_heapify(int[], int);

int main(void) {

}