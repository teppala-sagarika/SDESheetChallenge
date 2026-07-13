// ────────────────────────────────────────────────────────────
// Problem : Lowest Common Ancestor of a Binary Search Tree
// Platform: LeetCode
// URL     : https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/
// Language: cpp
// Date    : 7/13/2026, 7:25:37 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(h)
// Space Complexity: O(1)
// Notes           : point of split = LCA (one node to left and other to right)
// ────────────────────────────────────────────────────────────

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
            return nullptr;
        }
        //both to the ryt so go further right 
        if(root->val<p->val && root->val<q->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        //both to the left so go further left 
        if(root->val>p->val && root->val>q->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        return root; //got a split
    }
};