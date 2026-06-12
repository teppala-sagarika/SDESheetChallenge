// ────────────────────────────────────────────────────────────
// Problem : Linked List Cycle II
// Platform: LeetCode
// URL     : https://leetcode.com/problems/linked-list-cycle-ii/description/
// Language: cpp
// Date    : 6/12/2026, 11:07:35 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n)
// Space Complexity: O(1)
// Notes           : Floyd's algorithm
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                fast=head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;//or fast
            }
        }
        return nullptr;
    }
};