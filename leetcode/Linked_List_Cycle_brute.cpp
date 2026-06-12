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
        ListNode *temp=head;
        unordered_map<ListNode*,int> mp;
        while(temp!=nullptr){
            if(mp[temp]) return true;
            mp[temp]++;
            temp=temp->next;
        }
        return false;
    }
};

//T.C = O(n)
//S.C = O(n)
