#include "Student.h"

//Given an array nums of size n, return the majority element.

//The majority element appears more than ⌊n/2⌋ times.
//You may assume the majority element always exists in the array.

//Example 1:
//Input: nums = [3,2,3]
//Output: 3

//Example 2:
//Input: nums = [2,2,1,1,1,2,2]
//Output: 2


int majorityElement(int* nums, int numsSize) {
    int n = 0;                 // stores the max count found so far
    int majority = nums[0];    // initial candidate

    for (int i = 0; i < numsSize; i++) {
        int temp = 0;          // reset count for nums[i]

        for (int j = 0; j < numsSize; j++) {
            if (nums[j] == nums[i]) {
                temp++;
            }
        }

        if (temp > n) {
            majority = nums[i];
            n = temp;          // <-- crucial: update max count
        }
    }

    return majority;
}

