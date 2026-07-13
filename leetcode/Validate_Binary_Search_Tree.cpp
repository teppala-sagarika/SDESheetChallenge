// ────────────────────────────────────────────────────────────
// Problem : Validate Binary Search Tree
// Platform: LeetCode
// URL     : https://leetcode.com/problems/validate-binary-search-tree/submissions/2066175510/
// Language: cpp
// Date    : 7/13/2026, 7:02:12 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n)
// Space Complexity: O(1)
// Notes           : set a range for each node
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
    bool verify(TreeNode* root,long long l,long long h){
        if(!root){
            return true;
        }
        if(root->val<=l || root->val>=h){
            return false;
        }
        return verify(root->left,l,root->val)&&verify(root->right,root->val,h);
    }
    bool isValidBST(TreeNode* root) {
        //give range for each node
        return verify(root,LLONG_MIN,LLONG_MAX);
    }
};