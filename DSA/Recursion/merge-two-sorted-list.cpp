/*
========================================
Problem: Merge Two Sorted Lists
Platform: LeetCode
Language: C++
Approach: Iterative with Dummy Node
Time Complexity: O(n + m)
Space Complexity: O(1)
========================================

Example:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* dummy = new ListNode();
        ListNode* current = dummy;

        while (list1 != nullptr && list2 != nullptr) {

            if (list1->val <= list2->val) {
                current->next = list1;
                list1 = list1->next;
            } else {
                current->next = list2;
                list2 = list2->next;
            }

            current = current->next;
        }

        if (list1 != nullptr)
            current->next = list1;
        else
            current->next = list2;

        return dummy->next;
    }
};
