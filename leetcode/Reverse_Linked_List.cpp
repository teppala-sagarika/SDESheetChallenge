// ────────────────────────────────────────────────────────────
// Problem : Reverse Linked List
// Platform: LeetCode
// URL     : https://leetcode.com/problems/reverse-linked-list/submissions/2027711735/
// Language: cpp
// Date    : 6/9/2026, 9:39:06 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n)
// Space Complexity: O(n)
// Notes           : recursive approach
// ────────────────────────────────────────────────────────────

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* prev = nullptr;
        ListNode* temp = head;

        while(temp != nullptr) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }
};