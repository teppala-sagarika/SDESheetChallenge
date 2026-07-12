// ────────────────────────────────────────────────────────────
// Problem : Search in a Binary Search Tree
// Platform: LeetCode
// URL     : https://leetcode.com/problems/search-in-a-binary-search-tree/submissions/2064628989/
// Language: cpp
// Date    : 7/12/2026, 11:17:15 AM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(h)
// Space Complexity: O(h)
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root){
            return nullptr;
        }
        if(root->val==val){
            return root;
        }
        if(root->val>val){
            if(root->left)
            return searchBST(root->left,val);
        }
        return searchBST(root->right,val);
    }
};