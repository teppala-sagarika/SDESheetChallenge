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
    TreeNode* prev=nullptr;
    void flatten(TreeNode* root) {
        if(!root) return;
        flatten(root->right);//go complete ryt
        flatten(root->left);//if no ryt go left
        root->right=prev;//flatten
        root->left=nullptr;//remove
        prev=root;
    }
};

//T.C = O(n)
//S.C = O(h)
