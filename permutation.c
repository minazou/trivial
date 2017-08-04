#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void perm(int c, int n, int* output, int* used) {
    int i;
    if (c == n) {
        for (i = 0; i < n; i++) {
            printf("%d", output[i]);
        }
        printf("\n");
    } else {
        for (i = 1; i <= n; i++) {
            if (!used[i]) {
                used[i] = 1;
                output[c] = i;
                perm(c + 1, n, output, used);
                used[i] = 0;
            }
        }
    }
}

int main() {
    int n;
    int *output, *used;
    size_t size;

    scanf("%d", &n);

    size = (n + 1) * sizeof(int);
    output  = (int*)malloc(size);
    used = (int*)malloc(size);

    memset(output, 0, size);
    memset(used, 0, size);

    perm(0, n, output, used);

    free(output);
    free(used);
    return 0;
}
