#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define True 1
#define False 0

void print_arr(int *arr, int elements_amount) {
    for (int i = 0; i < elements_amount; i++)
        printf("%4d ", arr[i]);
    printf("\n");
}

int *create_rand_arr(int elements_amount) {
    int *arr = (int *)malloc(sizeof(int) * elements_amount);
    for (int i = 0; i < elements_amount; i++)
        arr[i] = rand() % 101;

    return arr;
}

int is_arr_sorted(int *arr, int elements_amount) { // 1 - True
    for (int i = 1; i < elements_amount; i++)
        if (arr[i] < arr[i - 1])
            return False;
    return True;
}

int run() {
    int is_working = True;
    for (int size = 100; size <= 1000; size += 100) {
        int *array = create_rand_arr(size);
        mergeSort(size, array);

        if (is_arr_sorted(array, size) == False) {
            is_working = False;
            break;
        }
        free(array);
    }
    if (is_working == True)
        printf("Сортировка прошла успешно\n");
    else
        printf("Сортировка не удалась\n");

    return EXIT_SUCCESS;
}

int main(int argc, char *argv[]) {
#ifdef _WIN32
    system("chcp 65001");
#endif

    srand(time(NULL));

    if (run() == EXIT_FAILURE)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
