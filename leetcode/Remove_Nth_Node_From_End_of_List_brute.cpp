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
        ListNode* temp=head;
        //length
        int l=0;
        while(temp!=nullptr){
            temp=temp->next;
            l++;
        }
        //remove head?
        if(n==l){
            ListNode* newHead=head->next;
            delete head;
            return newHead;
        }
        //go to len-n node
        temp=head;
        for(int i=1;i<=l-n-1;i++){
            temp=temp->next;
        }
        
        if (temp == nullptr || temp->next == nullptr) return head;

        ListNode* del=temp->next;
        temp->next=temp->next->next;
        delete del;

        return head;
    }
};

//T.C = O(l) + O(l-n)
//S.C = O(1)
