#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting.h"

int main () {
    system("chcp 65001");
    srand(time(NULL));

    int n = 10; int *a;
    a = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        a[i] = rand() % 101 - 50;
    }
    for (int i = 0; i < n; i++) {
        printf ("%d ", a[i]);
    }
    printf("\n");

    combSort(n, a);

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    //system("pause");
}
