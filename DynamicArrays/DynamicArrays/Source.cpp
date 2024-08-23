#include <stdio.h>
#include <stdlib.h>  // For malloc and free

int getSize();
int* createArray(int size);
void fillArray(int* arr, int size);
void printArray(int* arr, int size);

int main() {
    int size;
    int* arr;

    // Create an array of integers of the given size
    size = getSize();
    arr = createArray(size);

    // Fill the array with integers
    fillArray(arr, size);

    // Print the array
    printArray(arr, size);

    // Free allocated memory
    free(arr);

    return 0;
}

int getSize() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    return size;
}

// Create an array of integers of the given size
int* createArray(int size) {
    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Array created\n");
    return arr;
}

// Fill array with integers until user enters -1
void fillArray(int* arr, int size) {
    int num, i = 0;

    printf("Enter integers to fill the array (Enter -1 to stop):\n");

    while (i < size) {
        scanf("%d", &num);
        if (num == -1) break;
        arr[i++] = num;
    }
}

void printArray(int* arr, int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
