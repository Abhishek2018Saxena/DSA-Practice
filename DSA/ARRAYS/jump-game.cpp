/*
========================================
Problem: Jump Game
Platform: LeetCode
Language: C++
Approach: Greedy (Track Maximum Reach)
Time Complexity: O(n)
Space Complexity: O(1)
========================================

Example:
Input: nums = [2,3,1,1,4]
Output: true

Explanation:
You can jump from index 0 → 1 → 4 (last index).
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (i > maxReach) {
                return false; // Cannot reach this index
            }

            maxReach = max(maxReach, i + nums[i]);

            if (maxReach >= nums.size() - 1) {
                return true; // Last index reachable
            }
        }

        return true;
    }
};
