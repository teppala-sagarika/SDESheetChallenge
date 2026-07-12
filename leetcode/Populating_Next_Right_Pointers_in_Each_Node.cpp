// ────────────────────────────────────────────────────────────
// Problem : Populating Next Right Pointers in Each Node
// Platform: LeetCode
// URL     : https://leetcode.com/problems/populating-next-right-pointers-in-each-node/submissions/2064620756/
// Language: cpp
// Date    : 7/12/2026, 11:08:00 AM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n)
// Space Complexity: O(n)
// ────────────────────────────────────────────────────────────

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root){
            return root;
        }
        queue<Node*> q;
        q.push(root);
        vector<vector<Node*>> ans;
        while(!q.empty()){
            int n=q.size();
            vector<Node*> temp;
            for(int i=0;i<n;i++){
                Node* node=q.front();
                q.pop();
                temp.push_back(node);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            ans.push_back(temp);
        }
        for(auto &it:ans){
            int n=it.size();
            for(int i=0;i<n-1;i++){
                it[i]->next=it[i+1];
            }
            it[n-1]->next=nullptr;
        }
        return root;
    }
};