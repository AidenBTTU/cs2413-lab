/*
Question 2: Merge Sort

Description:
Implement merge sort to sort an integer array in ascending order.

Merge sort is a divide-and-conquer algorithm:
1. Divide the array into two halves.
2. Recursively sort each half.
3. Merge the two sorted halves into one sorted array.

You should implement:

    void mergeSort(int arr[], int size);

You may design your own helper functions.
Suggested helper functions:

    void mergeSortHelper(int arr[], int left, int right);
    void merge(int arr[], int left, int mid, int right);

Example:
Input:  [38, 27, 43, 3, 9, 82, 10]
Output: [3, 9, 10, 27, 38, 43, 82]

Notes:
- If the array is empty or has only one element, do nothing.
- You may use temporary arrays inside your merge function.

*/
void merge(int arr[], int left, int mid, int right);
void mergeSortHelper(int arr[], int left, int right);


void merge(int arr[], int left, int mid, int right) {
    int size = right - left + 1;
    int temp[size];

    int leftP = left;
    int rightP = mid + 1;
    int tempP = 0;

    while (leftP <= mid && rightP <= right) {
        if (arr[leftP] <= arr[rightP]) {
            temp[tempP++] = arr[leftP++];
        }
        else {
            temp[tempP++] = arr[rightP++];
        }
    }

    while (leftP <= mid) {
        temp[tempP++] = arr[leftP++];
    }

    while (rightP <= right) {
        temp[tempP++] = arr[rightP++];
    }

    for (int i = 0; i < size; i++) {
        arr[left + i] = temp[i];
    }
}
void mergeSortHelper(int arr[], int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;

    mergeSortHelper(arr, left, mid);
    mergeSortHelper(arr, mid + 1, right);

    merge(arr, left, mid, right);
}
void mergeSort(int arr[], int size) {
    // TODO: implement merge sort
    if (size <= 1) return;
    mergeSortHelper(arr, 0, size - 1);
}

