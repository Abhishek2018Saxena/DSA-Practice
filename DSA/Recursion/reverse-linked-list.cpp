/*
========================================
Problem: Reverse Linked List
Platform: LeetCode
Language: C++
Approach: Iterative (Three Pointers)
Time Complexity: O(n)
Space Complexity: O(1)
========================================

Example:
Input: 1 -> 2 -> 3 -> 4 -> 5
Output: 5 -> 4 -> 3 -> 2 -> 1
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = nullptr;
        ListNode* current = head;

        while (current != nullptr) {

            ListNode* nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        return prev;
    }
};
