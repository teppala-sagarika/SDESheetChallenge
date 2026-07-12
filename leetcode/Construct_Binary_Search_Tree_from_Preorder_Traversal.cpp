// ────────────────────────────────────────────────────────────
// Problem : Construct Binary Search Tree from Preorder Traversal
// Platform: LeetCode
// URL     : https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/submissions/2065245780/
// Language: cpp
// Date    : 7/12/2026, 10:33:33 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(3n)
// Space Complexity: O(1)
// Notes           : upper bound check for BST
// ────────────────────────────────────────────────────────────

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
    TreeNode* build(vector<int>& preorder,int &i,int upr_bound){
        if(i==preorder.size() || preorder[i]>upr_bound){
            return nullptr;
        }
        TreeNode* root=new TreeNode(preorder[i]);
        i++;
        root->left=build(preorder,i,root->val);
        root->right=build(preorder,i,upr_bound);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        //using upper bound only
        int i=0;
        return  build(preorder,i,INT_MAX);
    }
};