/*
========================================
Problem: Group Anagrams
Platform: LeetCode
Language: C++
Approach: Hash Map + Sorted String Key
Time Complexity: O(n * k log k)
Space Complexity: O(n)
========================================

Example:
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output:
[
  ["eat","tea","ate"],
  ["tan","nat"],
  ["bat"]
]
*/

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;

        for (string s : strs) {

            string key = s;
            sort(key.begin(), key.end());

            mp[key].push_back(s);
        }

        vector<vector<string>> result;

        for (auto &pair : mp) {
            result.push_back(pair.second);
        }

        return result;
    }
};
