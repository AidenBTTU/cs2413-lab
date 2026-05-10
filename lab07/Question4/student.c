/*
Question 4: Insertion Sort

Description:
Implement insertion sort for an integer array.

Insertion sort builds the sorted portion of the array one element at a time.
For each element, it inserts that element into the correct position among
the elements before it.

The function should sort the array in ascending order.

Example:
Input:  [5, 1, 4, 2, 8]
Output: [1, 2, 4, 5, 8]

Notes:
- If the array is empty or has only one element, do nothing.
- Do not use any built-in sorting function.
*/

void insertionSort(int arr[], int size) {
    // TODO: implement insertion sort
    (void)arr;
    (void)size;
    int temp;
    for(int i = 0; i < size; i++ ) {
        for(int j = i; j > 0; j--) {
            if(arr[j] < arr[j-1]) {
                temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
