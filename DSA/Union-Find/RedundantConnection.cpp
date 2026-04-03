/*
========================================
Problem: Number of Provinces
Platform: LeetCode
Language: C++
Approach: Union-Find (Disjoint Set Union - DSU)
Time Complexity: O(n^2 * α(n))
Space Complexity: O(n)
========================================

Example:
Input:
isConnected = [
 [1,1,0],
 [1,1,0],
 [0,0,1]
]

Output: 2

Explanation:
Cities 0 and 1 are connected → 1 province
City 2 is separate → 1 province
Total = 2 provinces
*/

class Solution {
public:
    vector<int> parent;

    // Find with path compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);  // compress path
        return parent[x];
    }

    // Union two sets
    void unite(int a, int b) {

        int rootA = find(a);
        int rootB = find(b);

        if (rootA != rootB) {
            parent[rootA] = rootB;
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();

        parent.resize(n);

        // Step 1: Initialize DSU
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        // Step 2: Union connected cities
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (isConnected[i][j] == 1) {
                    unite(i, j);
                }
            }
        }

        // Step 3: Count unique parents
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (parent[i] == i)
                count++;
        }

        return count;
    }
}; 