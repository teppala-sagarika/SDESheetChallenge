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
    void preorder(TreeNode* root,vector<int> &pre){
        if(!root){
            pre.push_back(-1);
            return;
        } 
        pre.push_back(root->val);
        preorder(root->left,pre);
        preorder(root->right,pre);
    }
    void postorder(TreeNode* root,vector<int> &post){
        if(!root){
            post.push_back(-1);
            return;
        }
        postorder(root->left,post);
        postorder(root->right,post);
        post.push_back(root->val);
    }
    bool isSymmetric(TreeNode* root) {
        vector<int> pre,post;
        preorder(root,pre);
        postorder(root,post);
        reverse(pre.begin(),pre.end());
        return pre==post;
    }
};

//T.C = O(n)
//S.C = O(n)
