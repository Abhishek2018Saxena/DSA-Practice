/*
========================================
Problem: Pow(x, n)
Platform: LeetCode
Language: C++
Approach: Binary Exponentiation
Time Complexity: O(log n)
Space Complexity: O(1)
========================================

Example:
Input: x = 2.0, n = 10
Output: 1024.0
*/

class Solution {
public:
    double myPow(double x, int n) {

        long long N = n;

        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double result = 1.0;

        while (N > 0) {

            if (N % 2 == 1)
                result *= x;

            x *= x;
            N /= 2;
        }

        return result;
    }
};
