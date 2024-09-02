#include <stdio.h>

int binarySearch(int *arr, int low, int high, int target);

void printArray(int *arr, int size);

const int MAX_SIZE = 10;

int main(void){

    int *arr = new int[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++){
        arr[i] = i;
    }

    printArray(arr, MAX_SIZE);

    int target = 5;
    int index = binarySearch(arr, 0, 9, target);
    printf("Index of %d is %d\n", target, index);
    
    return 0;
}

void printArray(int *arr, int size){
    printf("Array: ");
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int binarySearch(int *arr, int low, int high, int target){
    while (low <= high){
        int mid = low + (high - low) / 2;

        if (arr[mid] == target){
            return mid;
        } else if (arr[mid] < target){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}