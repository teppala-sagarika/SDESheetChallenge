// ────────────────────────────────────────────────────────────
// Problem : Reverse Nodes in k-Group
// Platform: LeetCode
// URL     : https://leetcode.com/problems/reverse-nodes-in-k-group/submissions/2031036233/
// Language: cpp
// Date    : 6/12/2026, 10:37:20 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(2n)
// Space Complexity: O(1)
// Notes           : linked lists
// ────────────────────────────────────────────────────────────

class Solution {
public:

    ListNode* reverseLL(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr != nullptr){
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev; // new head
    }

    ListNode* findkthNode(ListNode* temp, int k){
        while(temp != nullptr && k > 1){
            temp = temp->next;
            k--;
        }
        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || k == 1) return head;

        ListNode* temp = head;
        ListNode* prevLast = nullptr;

        while(temp != nullptr){

            ListNode* kthNode = findkthNode(temp, k);
            if(kthNode == nullptr){
                if(prevLast) prevLast->next = temp;
                break;
            }

            ListNode* nextNode = kthNode->next;

            kthNode->next = nullptr;
            ListNode* newHead = reverseLL(temp);

            if(temp == head){
                head = newHead;
            } else {
                prevLast->next = newHead;
            }

            prevLast = temp;
            temp = nextNode;
        }

        return head;
    }
};