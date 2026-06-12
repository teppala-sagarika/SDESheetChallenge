// ────────────────────────────────────────────────────────────
// Problem : Intersection of Two Linked Lists
// Platform: LeetCode
// URL     : https://leetcode.com/problems/intersection-of-two-linked-lists/submissions/2030837803/
// Language: cpp
// Date    : 6/12/2026, 6:47:51 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n+m)
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
    ListNode *collisionPt(ListNode* t1,ListNode* t2,int c){
        int x=c;
        while(x && t1!=nullptr){
            t1=t1->next;
            x--;
        }
        while(t1!=nullptr && t2!=nullptr){
            if(t1==t2){
                return t1;
            }
            t1=t1->next;
            t2=t2->next;
        }
        return nullptr;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        int n=0;
        while(tempA!=nullptr){
            n++;
            tempA=tempA->next;
        }
        int m=0;
        while(tempB!=nullptr){
            m++;
            tempB=tempB->next;
        }
        if(n<m){
            return collisionPt(headB,headA,m-n);
        }
        else{
            return collisionPt(headA,headB,n-m);
        }
    }
};

//T.C = O(n+m)
//S.C = O(1)