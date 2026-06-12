/*
Definition of special linked list:
struct ListNode
{
    int val;
    ListNode *next;
    ListNode *child;
    ListNode()
    {
        val = 0;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode* next2)
    {
        val = data1;
        next = next1;
        child = next1;
    }
};
*/

class Solution {
public:

    ListNode* merge(ListNode* l1, ListNode* l2){

        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;

        ListNode* result = nullptr;

        if(l1->val <= l2->val){

            result = l1;
            result->child = merge(l1->child, l2);

        }
        else{

            result = l2;
            result->child = merge(l1, l2->child);

        }

        result->next = nullptr;

        return result;
    }


    ListNode* flattenLinkedList(ListNode* head) {

        if(head == nullptr || head->next == nullptr)
            return head;


        // Flatten remaining lists
        head->next = flattenLinkedList(head->next);


        // Merge current child list with flattened next list
        head = merge(head, head->next);


        return head;
    }
};

//T.C = O(2nm)
//S.C = O(n)
