/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        TreeNode* cur=root;
        while(cur!=nullptr){
           if(cur->left!=nullptr){
            TreeNode* prev=cur->left;
            while(prev->right){
                prev=prev->right;//atlomst ryt of left subtree
            }
            //change 2 links
            prev->right=cur->right;
            cur->right=cur->left;
            //remove left
            cur->left=nullptr;
           }
           cur=cur->right;//if no left
        }
    }
};

//T.C = O(n)
//S.C = O(1)
