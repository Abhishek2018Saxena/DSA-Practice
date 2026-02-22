/*
========================================
Problem: Longest Repeating Character Replacement
Platform: LeetCode
Language: C++
Approach: Sliding Window + Max Frequency Tracking
Time Complexity: O(n)
Space Complexity: O(1)
========================================

Example:
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace one 'B' → "AAAA"
*/

#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {

        int count[26] = {0};
        int left = 0;
        int maxFreq = 0;
        int maxLength = 0;

        for (int right = 0; right < s.length(); right++) {

            count[s[right] - 'A']++;
            maxFreq = max(maxFreq, count[s[right] - 'A']);

            while ((right - left + 1) - maxFreq > k) {
                count[s[left] - 'A']--;
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
