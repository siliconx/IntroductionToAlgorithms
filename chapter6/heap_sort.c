#include <stdio.h>
#define N 9

int parent(int i) {
    return i / 2 - 1;
}

int left_child(int i) {
    return 2 * i + 1;
}

int right_child(int i) {
    return 2 * (i + 1);
}

int heap_sort(int[], int);
int build_max_heap(int[], int);
int max_heapify(int[], int, int);
int swap(int[], int, int);
int output(int[], int);

int main(void) {
    int array[N];
    printf("original array:\n");
    output(array, N);
    printf("sorting...\n");
    heap_sort(array, N);
    printf("sorted array:\n");
    output(array, N);
    return 0;
}

int heap_sort(int a[], int size) {
	build_max_heap(a, size);
	for (int i = size - 1; i > 0; --i) {
		swap(a, 0, i);
		--size;
		max_heapify(a, 0, size);
	}
	return 0;
}

int build_max_heap(int a[], int size) {
	for (int i = parent(size); i >= 0; --i) {
		max_heapify(a, i, size);
	}
	return 0;
}

int max_heapify(int a[], int i, int size) {
	int l = left_child(i);
	int r = right_child(i);
	int largest;
	if (l < size && a[l] > a[i]) {
		largest = l;
	} else {
		largest = i;
	}

	if (r < size && a[r] > a[largest]) {
		largest = r;
	}

	if (largest != i) {
		swap(a, i, largest);
		max_heapify(a, largest, size);
	}
	return 0;
}

int swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    return 0;
}

int output(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d, ", a[i]);
    }
    printf("\n");
    return 0;
}
