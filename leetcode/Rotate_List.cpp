// ────────────────────────────────────────────────────────────
// Problem : Rotate List
// Platform: LeetCode
// URL     : https://leetcode.com/problems/rotate-list/submissions/2031403326/
// Language: cpp
// Date    : 6/13/2026, 11:09:53 AM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n)
// Space Complexity: O(1)
// Notes           : linked list
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr || k == 0)
        return head;
        int len=0;
        ListNode* temp=head;
        while(temp->next!=nullptr){
            len++;
            temp=temp->next;
        }
        len++;
        temp->next=head;
        int rot=len-(k%len)-1;
        temp=head;
        while(rot){
            temp=temp->next;
            rot--;
        }
        head=temp->next;
        temp->next=nullptr;
        return head;
    }
};

//T.C = O(n)
//S.C = O(1)