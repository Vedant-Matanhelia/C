#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct MyArray {
    int total_size;
    int used_size;
    int *ptr;
} MyArray;

void CreateArray(MyArray *arr, int tSize, int used_size) {
    arr->total_size = tSize;
    arr->used_size = used_size;
    arr->ptr = (int *)malloc(tSize * sizeof(int));
}

void SetData(MyArray *arr) {
    int n;
    for (int i = 0; i < arr->used_size; i++) {
        printf("Enter the value at %d: ", i);
        scanf("%d", &n);
        arr->ptr[i] = n;
    }
}

void ShowArray(MyArray *arr) {
    for (int i = 0; i < arr->used_size; i++) {
        printf("Element %d: %d\n", i, arr->ptr[i]);
    }
}

int Insertion(MyArray *arr, int index, int data) {
    if (arr->used_size == arr->total_size) {
        printf("Cannot add. Array full.\n");
        return -1;
    }
    for (int i = arr->used_size - 1; i < index; i--) {
        arr->ptr[i + 1] = arr->ptr[i];
    }
    arr->ptr[index] = data;
    arr->used_size++;
    return 1;
}

int Deletion(MyArray *arr, int used_size, int index) {
    if (index > arr->total_size - 1) {
        printf("Cannot delete. The index is more than the size of the array\n");
        return -1;
    }
    for (int i = index; i < used_size; i++) {
        arr[i] = arr[i + 1];
    }
    arr->used_size--;
    return 1;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void BubbleSort(MyArray *arr) {
    for (int i = arr->used_size; i > -1; i--) {
        for (int j = 0; j < i; j++) {
            if (arr->ptr[j] > arr->ptr[j + 1]) {
                swap(&arr->ptr[j], &arr->ptr[j + 1]);
            }
        }
    }
}

void SelectionSort(MyArray *arr) {
    for (int i = 0; i < arr->used_size - 1; i++) {
        int minpos = i;
        for (int j = i; j < arr->used_size; j++) {
            if (arr->ptr[j] < arr->ptr[minpos]) {
                minpos = j;
            }
        }
        swap(&arr->ptr[i], &arr->ptr[minpos]);
    }
}

int LinearSearch(MyArray *arr, int value) {
    for (int i = 0; i < arr->used_size; i++) {
        if (arr->ptr[i] == value) {
            return i;
        }
    }
    return -1;
}

int BinarySearch(MyArray *arr, int element) {
    // The array should be sorted. so use bubble sort or selection sort before using the binary search
    int low, mid, high;
    high = arr->used_size - 1;
    low = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr->ptr[mid] == element) {
            return mid;
        }
        if (arr->ptr[mid] < element) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    MyArray arr;
    int value, index;
    CreateArray(&arr, 10, 6);
    SetData(&arr);
    // printf("Before Sorting\n");
    // ShowArray(&arr);
    // BubbleSort(&arr);
    Sleep(1000);
    SelectionSort(&arr);
    printf("After Sorting\n");
    ShowArray(&arr);
    printf("Which element do you want to search: ");
    scanf("%d\n", &value);
    index = BinarySearch(&arr, value);
    if (index == -1) {
        printf("The value is not in the array");
    } else {
        printf("The value was found at index %d", index);
    }
    return 0;
}