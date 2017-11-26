#include <stdio.h>
#define N 10

int randomized_select(int[], int, int, int);
int randomized_partition(int[], int, int);
int swap(int[], int, int);
int output(int[], int);

int main() {
    int a[N];
    for (int i = 0; i < N; ++i) {
        a[i] = i * i;
    }
    output(a, N);
    printf("%d\n", randomized_select(a, 0, N - 1, N -2));
    return 0;
}

int randomized_select(int a[], int p, int r, int i) {
    if (p == r) {  // a[] has only one element
        return a[p];
    }

    int q = randomized_partition(a, p, r);
    int k = q - p + 1;  // number of element in a[p, q]

    if (i == k) {  // the pivot value is the answer
        return a[q];
    } else if (i < k) {
        return randomized_select(a, p, q - 1, i);
    } else {
        return randomized_select(a, q + 1, r, i - k);
    }
}

int randomized_partition(int a[], int p, int r) {  // the most important function
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

