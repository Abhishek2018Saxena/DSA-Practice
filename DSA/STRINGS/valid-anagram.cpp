/*
========================================
Problem: Valid Anagram
Platform: LeetCode
Language: C++
Approach: Frequency Counting (26 letters)
Time Complexity: O(n)
Space Complexity: O(1)
========================================

Example:
Input: s = "anagram", t = "nagaram"
Output: true
*/

#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length() != t.length())
            return false;

        int count[26] = {0};

        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (count[i] != 0)
                return false;
        }

        return true;
    }
};
