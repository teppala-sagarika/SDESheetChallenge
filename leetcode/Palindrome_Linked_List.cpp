// ────────────────────────────────────────────────────────────
// Problem : Palindrome Linked List
// Platform: LeetCode
// URL     : https://leetcode.com/problems/palindrome-linked-list/submissions/2031056716/
// Language: cpp
// Date    : 6/12/2026, 10:57:35 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(2n)
// Space Complexity: O(1)
// Notes           : find middle and then reverse the second half but dont detach it (P.S: dont forget to make the list back to its original form)
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
    ListNode* reverseLL(ListNode *head){
        ListNode* prev=nullptr;
        ListNode* cur=head;
        while(cur!=nullptr){
            ListNode* front=cur->next;
            cur->next=prev;
            prev=cur;
            cur=front;
        }
        return prev;//newHead
    }
    bool isPalindrome(ListNode* head) {
        //find middle
        ListNode *slow=head,*fast=head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* newHead=reverseLL(slow->next);
        ListNode* first=head, *second=newHead;
        while(second!=nullptr){
            if(first->val!=second->val){
                reverseLL(newHead);
                return false;
            }
            first=first->next;
            second=second->next;
        }
        reverseLL(newHead);
        return true;
    }
};