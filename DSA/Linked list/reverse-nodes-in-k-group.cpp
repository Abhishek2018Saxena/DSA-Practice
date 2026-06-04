/*
========================================
Problem: Reverse Nodes in k-Group
Platform: LeetCode
Language: C++
Approach: Iterative Group Reversal
Time Complexity: O(n)
Space Complexity: O(1)
========================================

Example:
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
*/

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        if (!head || k == 1)
            return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevGroup = &dummy;

        while (true) {

            // Step 1: Check if k nodes exist
            ListNode* kth = prevGroup;
            for (int i = 0; i < k && kth != nullptr; i++)
                kth = kth->next;

            if (kth == nullptr)
                break;

            // Step 2: Identify boundaries
            ListNode* groupStart = prevGroup->next;
            ListNode* nextGroup = kth->next;

            // Step 3: Reverse k nodes
            ListNode* prev = nextGroup;
            ListNode* curr = groupStart;

            while (curr != nextGroup) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // Step 4: Reconnect
            prevGroup->next = kth;
            prevGroup = groupStart;
        }

        return dummy.next;
    }
};
