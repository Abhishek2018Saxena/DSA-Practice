/*
========================================
Problem: Maximum Product Subarray
Platform: LeetCode
Language: C++
Approach: Track Max and Min Product
Time Complexity: O(n)
Space Complexity: O(1)
========================================

Example:
Input: nums = [2,3,-2,4]
Output: 6

Explanation:
Subarray [2,3] gives maximum product = 6.
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int minProd = nums[0];
        int result = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            // If current number is negative, swap max and min
            if (nums[i] < 0) {
                swap(maxProd, minProd);
            }

            maxProd = max(nums[i], maxProd * nums[i]);
            minProd = min(nums[i], minProd * nums[i]);

            result = max(result, maxProd);
        }

        return result;
    }
};
