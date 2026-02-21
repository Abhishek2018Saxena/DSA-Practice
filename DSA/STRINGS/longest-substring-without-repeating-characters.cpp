/*
========================================
Problem: Longest Substring Without Repeating Characters
Platform: LeetCode
Language: C++
Approach: Sliding Window + Last Seen Index
Time Complexity: O(n)
Space Complexity: O(1)
========================================

Example:
Input: s = "abcabcbb"
Output: 3

Explanation:
Longest substring without repeating characters is "abc".
*/

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        vector<int> lastIndex(256, -1);  // Store last seen index
        int maxLength = 0;
        int left = 0;  // Left pointer of sliding window

        for (int right = 0; right < s.length(); right++) {

            if (lastIndex[s[right]] >= left) {
                left = lastIndex[s[right]] + 1;
            }

            lastIndex[s[right]] = right;

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
