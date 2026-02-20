/*
========================================
Problem: Contains Duplicate
Platform: LeetCode
Language: C++
Approach: Sorting
Time Complexity: O(n log n)
Space Complexity: O(1)
========================================

Example:
Input: nums = [1,2,3,1]
Output: true

Explanation:
After sorting → [1,1,2,3]
Since 1 appears twice, return true.
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                return true;
            }
        }

        return false;
    }
};
