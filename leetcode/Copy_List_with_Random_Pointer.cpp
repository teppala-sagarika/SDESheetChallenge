// ────────────────────────────────────────────────────────────
// Problem : Copy List with Random Pointer
// Platform: LeetCode
// URL     : https://leetcode.com/problems/copy-list-with-random-pointer/submissions/2031503642/
// Language: cpp
// Date    : 6/13/2026, 12:51:37 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n)
// Space Complexity: O(1)
// Notes           : linked list
// ────────────────────────────────────────────────────────────

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr) return nullptr;
        //insert nodes in btwn
        Node* temp=head;
        while(temp!=nullptr){
            Node* newNode=new Node(temp->val);
            newNode->next=temp->next;
            temp->next=newNode;
            temp=temp->next->next;
        }
        //update randoms
        temp=head;
        while(temp!=nullptr){
            if(temp->random)
                temp->next->random=temp->random->next;
            else
                temp->next->random=nullptr;
            temp=temp->next->next;
        }
        //update nexts and seperate lists
        temp=head;
        Node* copyHead=head->next;
        Node* copy=copyHead;

        while(temp!=nullptr){
            temp->next=temp->next->next;
            if(copy->next)
                copy->next=copy->next->next;
            temp=temp->next;
            copy=copy->next;
        }
        return copyHead;
    }
};

//T.C = O(n)
//S.C = O(1)