#include <stdio.h>  

int linearSearch(int* arr, int size, int target);
void addValues(int* arr, int size);
void printArray(int* arr, int size);

int main(void){

    int* arr = new int[10];

    addValues(arr, 10);
    printArray(arr, 10);

    int target = 5;
    printf("Linear search for %d\n", target);
    printf("Index: %d\n", linearSearch(arr, 10, target));

    delete[] arr;

    return 0;
}

void addValues(int* arr, int size){
    for (int i = 0; i < size; i++){
        printf("Enter a value: ");
        scanf("%d", &arr[i]);
    }
    printf("\n");
}

int linearSearch(int* arr, int size, int target){
    printf("Searching for %d\n", target);
    for (int i  = 0; i < size; i++){
        if(arr[i] == target){
            printf("Found %d at index %d\n", target, i);
            return i;
        }
    }
    printf("Not found\n");
    return -1;
}

void printArray(int* arr, int size){
    printf("Array: ");
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}