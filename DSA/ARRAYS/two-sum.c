/*
========================================
Problem: Two Sum
Platform: LeetCode
Language: C
Approach: Brute Force
Time Complexity: O(n^2)
Space Complexity: O(1)
========================================
*/

#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {

    // Allocate memory for result (2 indices)
    int* result = (int*)malloc(2 * sizeof(int));
    
    if (result == NULL) {
        return NULL; // Memory allocation failed
    }

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {

            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;

                *returnSize = 2;   // We are returning 2 elements
                return result;
            }
        }
    }
    // If no solution found
    *returnSize = 0;
    free(result);
    return NULL;
}


// output : 
          /*
             Example:
             Input: nums = [2,7,11,15], target = 9
             Output: [0,1]
          */
