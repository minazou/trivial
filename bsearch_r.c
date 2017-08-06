#include <stdio.h>

int bsearch(int *a, int l, int r, int v, int find_right) {
    int m, lor;
    if (l <= r) {
        m = (l + r) / 2;
        if (a[m] > v) {
            return bsearch(a, l, m - 1, v, find_right);
        } else if (a[m] < v) {
            return bsearch(a, m + 1, r, v, find_right);
        } else {
            if (!find_right) {
                lor = bsearch(a, l, m - 1, v, find_right);
            } else {
                lor = bsearch(a, m + 1, r, v, find_right);
            }
            return lor == -1? m: lor;
        }
    }
    return -1;
}


int main() {
    int a[] = {0, 1, 2, 3, 3, 3, 3, 4, 4, 4};
    int l = 0;
    int r = sizeof(a) / sizeof(int) - 1;
    int idl, idr;

    idl = bsearch(a, l, r, 4, 0);
    idr = bsearch(a, l, r, 4, 1);

    if (idl != -1) {
        printf("%d\n", idr - idl + 1);
    } else {
        printf("%d\n", 0);
    }
    return 0;
}
