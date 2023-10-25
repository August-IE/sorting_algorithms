#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int *left, int left_size, int *right, int right_size) {
    int i, j, k;
    i = j = k = 0;

    while (i < left_size && j < right_size) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left_size) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < right_size) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort_recursive(int *arr, int *temp, int start, int end) {
    if (start < end - 1) {
        int mid = (start + end) / 2;
        merge_sort_recursive(arr, temp, start, mid);
        merge_sort_recursive(arr, temp, mid, end);
        merge(arr + start, arr + start, mid - start, arr + mid, end - mid);
        for (int i = start; i < end; i++) {
            temp[i] = arr[i];
        }
        for (int i = start; i < end; i++) {
            arr[i] = temp[i];
        }
    }
}

void merge_sort(int *arr, size_t size) {
    if (size <= 1) {
        return; // Base case: array is already sorted
    }

    int *temp = (int *)malloc(size * sizeof(int));
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    merge_sort_recursive(arr, temp, 0, size);

    free(temp);
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    merge_sort(arr, size);

    printf("Sorted array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
