#include <stdbool.h>

/*
Question 1: Bubble Sort

Description:
Implement two versions of bubble sort for an integer array.

1. bubbleSort:
   Implement the basic bubble sort algorithm.
   Repeatedly compare adjacent elements and swap them if they are
   in the wrong order. After each pass, the largest unsorted element
   should move to its correct position.

2. bubbleSortOptimized:
   Implement an improved version of bubble sort.
   This version should stop early if a full pass completes without
   any swaps, which means the array is already sorted.

Both functions should sort the array in ascending order.

Example:
Input:  [5, 1, 4, 2, 8]
Output: [1, 2, 4, 5, 8]

Notes:
- If the array is empty or has only one element, do nothing.
- You may write a helper function such as swap(...) if you want.
*/
bool swap(int arr[], int first);
void bubbleSort(int arr[], int size);

bool swap(int arr[], int first) {
    int tempElement = arr[first];
    if (arr[first + 1] < arr[first]) {
        arr[first] = arr[first + 1];
        arr[first + 1] = tempElement;
        return true;
    }
    return false;
}
void bubbleSort(int arr[], int size) {
    // TODO: implement basic bubble sort
    if (size == 0) {
        return;
    }
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            swap(arr, j);
        }
    }

}

void bubbleSortOptimized(int arr[], int size) {
    // TODO: implement optimized bubble sort with early stopping
    if (size == 0) {
        return;
    }
    bool swapFlag = false;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (swap(arr, j) == true) {
                swapFlag = true;
            } 
        }
        if (swapFlag == false) {
            return;
        }
    }
}


