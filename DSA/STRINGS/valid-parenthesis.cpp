/*
========================================
Problem: Valid Parentheses
Platform: LeetCode
Language: C++
Approach: Stack (LIFO principle)
Time Complexity: O(n)
Space Complexity: O(n)
========================================

Example:
Input: s = "()[]{}"
Output: true
*/

#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for (char c : s) {

            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else {

                if (st.empty())
                    return false;

                char top = st.top();
                st.pop();

                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }

        return st.empty();
    }
};
