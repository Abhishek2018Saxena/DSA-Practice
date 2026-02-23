/*
========================================
Problem: Swap Nodes in Pairs
Platform: LeetCode
Language: C++
Approach: Iterative with Dummy Node
Time Complexity: O(n)
Space Complexity: O(1)
========================================

Example:
Input: 1 -> 2 -> 3 -> 4
Output: 2 -> 1 -> 4 -> 3
*/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;

        while (prev->next != nullptr && prev->next->next != nullptr) {

            ListNode* first = prev->next;
            ListNode* second = first->next;

            first->next = second->next;
            second->next = first;
            prev->next = second;

            prev = first;
        }

        return dummy->next;
    }
};
