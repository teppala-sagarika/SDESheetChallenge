// ────────────────────────────────────────────────────────────
// Problem : Delete Node in a Linked List
// Platform: LeetCode
// URL     : https://leetcode.com/problems/delete-node-in-a-linked-list/description/
// Language: cpp
// Date    : 6/10/2026, 10:48:49 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(1)
// Space Complexity: O(1)
// Notes           : linked list
// ────────────────────────────────────────────────────────────

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next=node->next->next;
    }
};