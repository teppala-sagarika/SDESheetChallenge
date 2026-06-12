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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int> mp;
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        while(tempA!=nullptr){
            mp[tempA]++;
            tempA=tempA->next;
        }
        while(tempB!=nullptr){
            if(mp[tempB]){
                return tempB;
            }
            tempB=tempB->next;
        }
        return nullptr;
    }
};

//T.C= O(n+m)
//S.C = O(n)
