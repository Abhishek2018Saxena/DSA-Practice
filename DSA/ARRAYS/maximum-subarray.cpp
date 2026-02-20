/*
========================================
Problem: Maximum Subarray
Platform: LeetCode
Language: C++
Approach: Kadane’s Algorithm
Time Complexity: O(n)
Space Complexity: O(1)
========================================

Example:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6

Explanation:
Subarray [4,-1,2,1] has maximum sum = 6.
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum = nums[0];
        int max_sum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            current_sum = max(nums[i], current_sum + nums[i]);
            max_sum = max(max_sum, current_sum);
        }

        return max_sum;
    }
};
