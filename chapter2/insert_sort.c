#include <stdio.h>
#define N 1000000

int insert_sort(int[], int);
int output(int[], int);

int main(void) {
    int array[N];
    printf("original array:\n");
    output(array, N);
    insert_sort(array, N);
    printf("sorted array:\n");
    output(array, N);
    return 0;
}

int insert_sort(int a[], int n) {
    int i;
    int j;
    int key;
    for (i = 1; i < n; ++i) {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            --j;
        }
        a[j + 1] = key;
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
