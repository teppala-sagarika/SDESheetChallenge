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

    ListNode* convert(vector<int>& arr){

        if(arr.size()==0) return nullptr;

        ListNode* head = new ListNode(arr[0]);
        ListNode* temp = head;

        for(int i=1;i<arr.size();i++){

            ListNode* newNode = new ListNode(arr[i]);

            temp->child = newNode;
            temp = temp->child;
        }

        return head;
    }


    ListNode* flattenLinkedList(ListNode* &head) {

        vector<int> arr;

        ListNode* temp = head;

        while(temp != nullptr){

            ListNode* t2 = temp;

            while(t2 != nullptr){

                arr.push_back(t2->val);
                t2 = t2->child;
            }

            temp = temp->next;
        }


        sort(arr.begin(), arr.end());

        return convert(arr);
    }
};

//T.C = O(n*m)*2 + O((n*m) log (n*m))
//S.C = O(n*m)*2
