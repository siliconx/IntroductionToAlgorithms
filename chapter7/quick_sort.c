#include <stdio.h>
#define N 9999

int quick_sort(int[], int, int);
int partition(int[], int, int);
int swap(int[], int, int);
int output(int[], int);

int main(void) {
    int array[N];
    printf("original array:\n");
    //output(array, N);
    printf("sorting...\n");
    quick_sort(array, 0, N - 1);
    printf("sorted array:\n");
    //output(array, N);
    return 0;
}

int quick_sort(int a[], int p, int r) {
    if (p < r) {
        int q = partition(a, p, r);
        quick_sort(a, p, q - 1);
        quick_sort(a, q + 1, r);
    }
    return 0;
}

int partition(int a[], int p, int r) {  // the most important function
    int pivot = a[r];
    int i = p - 1;
    for (int j = p; j < r; ++j) {
        if (a[j] <= pivot) {
            // 把比小于等于pivot的元素放在前面
            ++i;
            swap(a, i, j);
        }
    }
    swap(a, i + 1, r);
    return i + 1;
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
