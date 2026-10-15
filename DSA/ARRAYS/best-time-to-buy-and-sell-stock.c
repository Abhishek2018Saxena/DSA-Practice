/*
========================================
Problem: Best Time to Buy and Sell Stock
Platform: LeetCode
Language: C
Approach: Single Pass (Optimal)
Time Complexity: O(n)
Space Complexity: O(1)
========================================

Example:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation:
Buy at price = 1
Sell at price = 6
Profit = 6 - 1 = 5
*/

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 0) return 0;

    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else {
            int profit = prices[i] - minPrice;
            if (profit > maxProfit) {
                maxProfit = profit;
            }
        }
    }

    return maxProfit;
}
