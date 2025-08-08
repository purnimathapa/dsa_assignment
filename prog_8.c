#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n, int* cmp, int* swap) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*cmp)++;
            if (arr[j] > arr[j + 1]) {
                (*swap)++;
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}

void selectionSort(int arr[], int n, int* cmp, int* swap) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            (*cmp)++;
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            (*swap)++;
            int t = arr[i];
            arr[i] = arr[min];
            arr[min] = t;
        }
    }
}

void insertionSort(int arr[], int n, int* cmp, int* swap) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            (*cmp)++;
            arr[j + 1] = arr[j];
            j--;
            (*swap)++;
        }
        (*cmp)++;
        arr[j + 1] = key;
    }
}

void merge(int arr[], int l, int m, int r, int* cmp, int* swap) {
    int n1 = m - l + 1, n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        (*cmp)++;
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else {
            arr[k++] = R[j++];
            (*swap)++;
        }
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r, int* cmp, int* swap) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m, cmp, swap);
        mergeSort(arr, m + 1, r, cmp, swap);
        merge(arr, l, m, r, cmp, swap);
    }
}

int main() {
    int N, choice;
    printf("Enter number of elements: ");
    scanf("%d", &N);

    int arr[N];
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 1000 + 1;
    }

    printf("Choose sorting algorithm:\n");
    printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Merge Sort\n");
    scanf("%d", &choice);

    int cmp = 0, swap = 0;
    int copy[N];
    for (int i = 0; i < N; i++) copy[i] = arr[i];

    printf("Before sorting:\n");
    for (int i = 0; i < N; i++) printf("%d ", arr[i]);
    printf("\n");

    switch (choice) {
        case 1: bubbleSort(copy, N, &cmp, &swap); break;
        case 2: selectionSort(copy, N, &cmp, &swap); break;
        case 3: insertionSort(copy, N, &cmp, &swap); break;
        case 4: mergeSort(copy, 0, N - 1, &cmp, &swap); break;
        default: printf("Invalid choice.\n"); return 1;
    }

    printf("After sorting:\n");
    for (int i = 0; i < N; i++) printf("%d ", copy[i]);
    printf("\n");

    printf("Comparisons: %d\n", cmp);
    printf("Swaps/Shifts: %d\n", swap);

    return 0;
}
