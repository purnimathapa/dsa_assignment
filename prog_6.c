#include <stdio.h>

void maxHeapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2*i + 1, r = 2*i + 2;
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest]) largest = r;
    if (largest != i) {
        int temp = arr[i]; arr[i] = arr[largest]; arr[largest] = temp;
        maxHeapify(arr, n, largest);
    }
}

void minHeapify(int arr[], int n, int i) {
    int smallest = i;
    int l = 2*i + 1, r = 2*i + 2;
    if (l < n && arr[l] < arr[smallest]) smallest = l;
    if (r < n && arr[r] < arr[smallest]) smallest = r;
    if (smallest != i) {
        int temp = arr[i]; arr[i] = arr[smallest]; arr[smallest] = temp;
        minHeapify(arr, n, smallest);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) maxHeapify(arr, n, i);
}

void buildMinHeap(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) minHeapify(arr, n, i);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int data[] = {5, 3, 8, 4, 1, 2};
    int n = sizeof(data)/sizeof(data[0]);

    printf("Original array:\n");
    printArray(data, n);

    int maxArr[10], minArr[10];
    for (int i = 0; i < n; i++) {
        maxArr[i] = minArr[i] = data[i];
    }

    buildMaxHeap(maxArr, n);
    buildMinHeap(minArr, n);

    printf("Max Heap:\n");
    printArray(maxArr, n);

    printf("Min Heap:\n");
    printArray(minArr, n);

    return 0;
}
