#include <stdio.h>
#include <stdlib.h>

typedef struct MyArray {
    int total_size;
    int used_size;
    int* arr;
} MyArray;

void createArray(MyArray* arr, int total_size, int used_size) {
    arr->total_size = total_size;
    arr->used_size = used_size;
    arr->arr = (int*)malloc(used_size * sizeof(int));
}

void setData(MyArray* arr) {
    int n;
    for (int i = 0; i < arr->used_size; i++) {
        printf("Enter the value at index %d: ", i);
        scanf("%d\n", &n);
        arr->arr[i] = n;
    }
}

void displayArray(MyArray* arr) {
    for (int i = 0; i < arr->used_size; i++) {
        printf("The value at index %d: %d\n", i, arr->arr[i]);
    }
}

int main() {
    MyArray* arr;
    createArray(arr, 10, 5);
    setData(arr);
    displayArray(arr);
    return 0;
}