#include <stdio.h>
#define N 10

int counting_sort(int[], int[], int, int);
int output(int[], int);

int main(void) {
    int a[N] = {9, 8, 1, 2, 2, 4, 6, 6, 7, 1};
    int b[N];
    counting_sort(a, b, N, 9);
    output(b, N);
    return 0;
}

int counting_sort(int a[], int b[], int n, int k) {
    int i;
    int c[k + 1];

    // initialize
    for (i = 0; i < k + 1; ++i) {
        c[i] = 0;
    }

    for (i = 0; i < n; ++i) {
        ++c[a[i]];  // c[i] now contains the number of elements equal to i
    }
    output(c, k + 1);

    for (i = 1; i < k + 1; ++i) {
        c[i] += c[i - 1];  // c[i] now contains the number of elements less than or equal to i
    }
    output(c, k + 1);

    for (i = n - 1; i >= 0; --i) {
        b[--c[a[i]]] = a[i];
    }
    return 0;
}

int output(int a[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d, ", a[i]);
    }
    printf("\n");
    return 0;
}
