/*
========================================
Problem: Product of Array Except Self
Platform: LeetCode
Language: C++
Approach: Prefix + Suffix Products
Time Complexity: O(n)
Space Complexity: O(1) (excluding output array)
========================================

Example:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Explanation:
Each element is product of all elements except itself.
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);

        // Step 1: Prefix products
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            answer[i] = prefix;
            prefix *= nums[i];
        }

        // Step 2: Suffix products
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }

        return answer;
    }
};
