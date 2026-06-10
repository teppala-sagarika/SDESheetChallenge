// ────────────────────────────────────────────────────────────
// Problem : Add Two Numbers
// Platform: LeetCode
// URL     : https://leetcode.com/problems/add-two-numbers/submissions/2028882854/
// Language: cpp
// Date    : 6/10/2026, 10:34:26 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(max(n, m))
// Space Complexity: O(1)
// Notes           : linked list (use dummy)
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode();
    ListNode* temp=dummy;
    int cnt=0;
    while(l1!=nullptr||l2!=nullptr||cnt){
        int sum=0;
        if(l1!=nullptr){
            sum+=l1->val;
            l1=l1->next;
        }
        if(l2!=nullptr){
            sum+=l2->val;
            l2=l2->next;
        }
        sum+=cnt;
        int dig=sum%10;
        cnt = sum / 10;
        ListNode* node=new ListNode(dig);
        temp->next=node;
        temp=temp->next;
    }
    return dummy->next;
    }
};