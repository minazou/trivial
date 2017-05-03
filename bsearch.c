#include <stdio.h>

int bsearch(int *a, int len, int v, int isRight) {
    int left = 0, right = len - 1, mid;
    int result = -1;
    while (left <= right) {
        mid = (left + right) / 2;
        if (a[mid] == v) {
            result = mid;
            if (isRight) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        } else if (a[mid] < v) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int main() {
    int a[] = {0, 1, 2, 3, 3, 3, 3, 4, 4, 4};
    int l, r;
    int len = sizeof(a) / sizeof(int);

    l = bsearch(a, len, 4, 0);
    r = bsearch(a, len, 4, 1);

    if (l != -1) {
        printf("%d\n", r - l + 1);
    } else {
        printf("%d\n", 0);
    }
    return 0;
}
