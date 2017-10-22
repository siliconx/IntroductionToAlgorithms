#include <stdio.h>
#define N 10

int find_max_subarray(int[], int, int);
int find_max_crossing_subarray(int[], int, int, int);

int main(void) {
    int array[N] = {12, 3, -7, 4, 6, -8, 3, -2, 8, 4};
    printf("%d\n", find_max_subarray(array, 0, N - 1));
    return 0;
}


int find_max_subarray(int a[], int low, int high) {
    if (low == high) {
        return a[low];
    }

    int mid = (low + high) / 2;
    int left_sum = find_max_subarray(a, low, mid);
    int right_sum = find_max_subarray(a, mid + 1, high);
    int cross_sum = find_max_crossing_subarray(a, low, mid, high);

    if (left_sum >= right_sum && left_sum >= cross_sum) {
        return left_sum;
    } else if (right_sum >= left_sum && right_sum >= cross_sum) {
        return right_sum;
    } else {
        return cross_sum;
    }
}

int find_max_crossing_subarray(int a[], int low, int mid, int high) {
    int left_sum = a[mid];
    int right_sum = a[mid + 1];
    int sum = 0;
    int i;

    for (i = mid; i >= low; --i) {
        sum += a[i];
        if (sum > left_sum) {
            left_sum = sum;
        }
    }

    sum = 0;
    for (i = mid + 1; i <= high; ++i) {
        sum += a[i];
        if (sum > right_sum) {
            right_sum = sum;
        }
    }

    return left_sum + right_sum;
}
