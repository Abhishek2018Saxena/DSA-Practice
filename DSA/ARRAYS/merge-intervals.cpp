/*
========================================
Problem: Merge Intervals
Platform: LeetCode
Language: C++
Approach: Sorting + Merging
Time Complexity: O(n log n)
Space Complexity: O(n)
========================================

Example:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]

Explanation:
[1,3] and [2,6] overlap → merged into [1,6].
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {

            vector<int>& last = result.back();

            if (intervals[i][0] <= last[1]) {
                last[1] = max(last[1], intervals[i][1]);
            } else {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};
