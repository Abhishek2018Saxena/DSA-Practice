/*
========================================
Problem: Sort Colors
Platform: LeetCode
Language: C++
Approach: Dutch National Flag Algorithm
Time Complexity: O(n)
Space Complexity: O(1)
========================================

Example:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Explanation:
Sort 0s, 1s, and 2s in one pass using 3 pointers.
*/

#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while (mid <= high) {

            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else {  // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
