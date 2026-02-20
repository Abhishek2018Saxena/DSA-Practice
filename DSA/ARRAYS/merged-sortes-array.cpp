/*
========================================
Problem: Merge Sorted Array
Platform: LeetCode
Language: C++
Approach: Two Pointers (From Back)
Time Complexity: O(m + n)
Space Complexity: O(1)
========================================

Example:
Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6], n = 3

Output:
[1,2,2,3,5,6]

Explanation:
Merge nums2 into nums1 in sorted order.
*/

#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m - 1;        // Last valid element in nums1
        int j = n - 1;        // Last element in nums2
        int k = m + n - 1;    // End of nums1

        while (i >= 0 && j >= 0) {

            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        while (j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};
