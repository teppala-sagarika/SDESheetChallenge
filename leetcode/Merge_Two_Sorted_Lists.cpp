// ────────────────────────────────────────────────────────────
// Problem : Merge Two Sorted Lists
// Platform: LeetCode
// URL     : https://leetcode.com/problems/merge-two-sorted-lists/submissions/2027864579/
// Language: cpp
// Date    : 6/9/2026, 11:51:15 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O((n + m) log(n + m))
// Space Complexity: O(n+m)
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> a;
         ListNode* temp1 = list1;
        while(temp1!=NULL){
            a.push_back(temp1->val);
            temp1=temp1->next;
        } 
         ListNode* temp2 = list2;
         while(temp2!=NULL){
            a.push_back(temp2->val);
            temp2=temp2->next;
        } 
        sort(a.begin(),a.end());
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        for (int val : a) {
            curr->next = new ListNode(val);
            curr = curr->next;
        }

        return dummy->next;
    }
};