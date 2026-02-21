/*
========================================
Problem: Longest Palindromic Substring
Platform: LeetCode
Language: C++
Approach: Expand Around Center
Time Complexity: O(n^2)
Space Complexity: O(1)
========================================

Example:
Input: s = "babad"
Output: "bab" or "aba"
*/

#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {

        if (s.empty()) return "";

        int start = 0;
        int maxLength = 1;

        for (int i = 0; i < s.length(); i++) {

            expandFromCenter(s, i, i, start, maxLength);       // Odd length
            expandFromCenter(s, i, i + 1, start, maxLength);   // Even length
        }

        return s.substr(start, maxLength);
    }

private:
    void expandFromCenter(string &s, int left, int right,
                          int &start, int &maxLength) {

        while (left >= 0 && right < s.length() &&
               s[left] == s[right]) {

            int currentLength = right - left + 1;

            if (currentLength > maxLength) {
                start = left;
                maxLength = currentLength;
            }

            left--;
            right++;
        }
    }
};
