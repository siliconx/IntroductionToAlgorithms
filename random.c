#include <stdio.h>
#define N 9

int counting_sort(int[], int[], int, int);
int output(int[], int);

int main(void) {
    int a[N];
    for (int i = 0; i < N; ++i) {
        a[i] = N - i;
    }
    int b[N];
    counting_sort(a, b, N, 9);
    output(b, N);
    return 0;
}

int counting_sort(int a[], int b[], int n, int k) {
    int c[k + 1];
    int i;
    for (i = 0; i < k + 1; ++i) {
        c[i] = 0;  // initialize
    }

    for (i = 0; i < n; ++i) {
        ++c[a[i]];
    }

    for (i = 0; i <= k; ++i) {
        c[i] += c[i - 1];
    }
    for (i = n - 1; i >= 0; --i) {
        b[c[a[i]]] = a[i];
        c[a[i]] = c[a[i]] - 1;
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
