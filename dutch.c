#include <stdio.h>

#define M 0
#define swap(x, y) {int tmp = x; x = y; y = tmp;}

int cmp(int v) {
    if (v < M) {
        return -1;
    } else if (v > M) {
        return 1;
    } else {
        return 0;
    }
}

void sort(int *a, int len, int (*cmp)(int)) {
    int i = 0, j = 0, k = len - 1;
    while (j <= k) {
        if (cmp(a[j]) == 1) {
            swap(a[j], a[k]);
            k--;
        } else if (cmp(a[j]) == -1) {
            swap(a[j], a[i]);
            i++;
            j++;
        } else {
            j++;
        }
    }
}

int main() {
    int a[] = {-10, 0, 10, 10, -10, 0, 10, -10, -2, 3, 0, 0, 12};
    int i;
    int len = sizeof(a) / sizeof(int);

    for (i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    sort(a, len, cmp);

    for (i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
