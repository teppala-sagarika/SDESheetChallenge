// ────────────────────────────────────────────────────────────
// Problem : Remove Nth Node From End of List
// Platform: LeetCode
// URL     : https://leetcode.com/problems/remove-nth-node-from-end-of-list/submissions/2028814512/
// Language: cpp
// Date    : 6/10/2026, 9:32:50 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n)
// Space Complexity: O(1)
// Notes           : fast and slow pointers
// ────────────────────────────────────────────────────────────

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head;
        for(int i=0;i<n;i++){
            fast=fast->next;
        }

        if(fast==nullptr){
            ListNode* newHead=head->next;
            delete head;
            return newHead;
        }

        ListNode* slow=head;
        while(fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next;
        }

        ListNode* del=slow->next;
        slow->next=slow->next->next;
        delete del;

        return head;
    }
};