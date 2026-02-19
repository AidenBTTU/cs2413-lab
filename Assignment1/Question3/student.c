#include "Student.h"
#include <stdlib.h>

//You are given a large integer represented as an integer array digits, where:

//digits[i] is the i-th digit of the integer
//digits are ordered from most significant to least significant
//there are no leading 0s (except the number 0 itself in some of our tests)
//Goal: Add 1 to the number and return the resulting digits array.

//Example 1:
//Input: digits = [4,3,2,1]
//Output: [4,3,2,2]
//Explanation: The array represents the integer 4321.
//Incrementing by one gives 4321 + 1 = 4322.
//Thus, the result should be [4,3,2,2].

//Example 2:
//Input: digits = [9]
//Output: [1,0]
//Explanation: The array represents the integer 9.
//Incrementing by one gives 9 + 1 = 10.
//Thus, the result should be [1,0].

//Return value (int*): the output digits array.
//Output parameter (returnSize): set *returnSize to the number of digits in the returned array.


int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int i = digitsSize - 1;

    // Always allocate a new array
    int* result = (int*)malloc(digitsSize * sizeof(int));
    for (int j = 0; j < digitsSize; j++) {
        result[j] = digits[j];
    }

    while (i >= 0 && result[i] == 9) {
        result[i] = 0;
        i--;
    }

    if (i < 0) {  // All digits were 9
        int* newDigits = (int*)malloc((digitsSize + 1) * sizeof(int));
        newDigits[0] = 1;
        for (int j = 1; j <= digitsSize; j++) {
            newDigits[j] = 0;
        }
        free(result);  // free temporary array
        *returnSize = digitsSize + 1;
        return newDigits;
    }

    result[i] += 1;
    *returnSize = digitsSize;
    return result;
}