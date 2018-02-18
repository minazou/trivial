#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define swap(a, b) {int tmp = a; a = b; b = tmp;}

int partition(int *arr, int left, int right) {
    int pivot = arr[right];
    int p_idx = left;
    for (int i = left; i < right; i++) {
        if (arr[i] <= pivot) {
            swap(arr[i], arr[p_idx]);
            p_idx++;
        }
    }
    swap(arr[right], arr[p_idx]);
    return p_idx;
}

void quicksort(int *arr, int left, int right) {
    if (left >= right) return;
    int p_idx = partition(arr, left, right);
    quicksort(arr, left, p_idx - 1);
    quicksort(arr, p_idx + 1, right);
}

int main(int argc, char **argv) {
    if (argc < 2) return 0;

    srand(time(NULL));

    int n = atoi(argv[1]);
    int *arr = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100000;
        printf("%d ", arr[i]);
    }

    quicksort(arr, 0, n - 1);

    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}
