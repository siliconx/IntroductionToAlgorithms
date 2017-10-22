#include <stdio.h>
#define N 101

int merge_sort(int[], int, int);
int merge(int[], int, int, int);
int output(int[], int);

int main(void) {
    int array[N];
    output(array, N);
    merge_sort(array, 0, N - 1);
    output(array, N);
    return 0;
}

int merge_sort(int a[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(a, p, q);
        merge_sort(a, q + 1, r);
        merge(a, p, q, r);
    }
    return 0;
}

int merge(int a[], int p, int q, int r) {
    int n = r - p + 1;  // len of subarray
    int temp[n];  // to store sorted subarray
    int i = p;  // left index
    int j = q + 1; // right index
    int k = 0;  // temp array's index
    int t;  // temp number
    while (i <= q || j <= r) {
        if (i > q) {  // left side reach the end
            t = a[j++];
        } else if (j > r) {  // right side reach the end
            t = a[i++];
        } else {  // find the min value
            if (a[i] < a[j]) {
                t = a[i++];
            } else {
                t = a[j++];
            }
        }
        temp[k++] = t;
    }

    // transport data from temp array to real array
    for (k = 0; k < n; ++k) {
        a[p + k] = temp[k];
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
