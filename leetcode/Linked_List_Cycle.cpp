// ────────────────────────────────────────────────────────────
// Problem : Linked List Cycle
// Platform: LeetCode
// URL     : https://leetcode.com/problems/linked-list-cycle/submissions/2030925036/
// Language: cpp
// Date    : 6/12/2026, 8:33:50 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n)
// Space Complexity: O(1)
// Notes           : Tortoise and hare algorithm
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
    bool hasCycle(ListNode *head) {
        ListNode *slow=head,*fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                return true;
            }
        }
        return false;
    }
};

