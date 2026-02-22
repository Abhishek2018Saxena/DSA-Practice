/*
========================================
Problem: Valid Palindrome
Platform: LeetCode
Language: C++
Approach: Two Pointers
Time Complexity: O(n)
Space Complexity: O(1)
========================================

Example:
Input: s = "A man, a plan, a canal: Panama"
Output: true
*/

#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {

        int left = 0;
        int right = s.length() - 1;

        while (left < right) {

            while (left < right && !isalnum(s[left]))
                left++;

            while (left < right && !isalnum(s[right]))
                right--;

            if (tolower(s[left]) != tolower(s[right]))
                return false;

            left++;
            right--;
        }

        return true;
    }
};
