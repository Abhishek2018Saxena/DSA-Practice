/*
========================================
Problem: Remove Nth Node From End of List
Platform: LeetCode
Language: C++
Approach: Two Pointers (Fast & Slow)
Time Complexity: O(n)
Space Complexity: O(1)
========================================

Example:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return dummy->next;
    }
};
