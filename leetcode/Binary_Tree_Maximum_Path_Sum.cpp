// ────────────────────────────────────────────────────────────
// Problem : Binary Tree Maximum Path Sum
// Platform: LeetCode
// URL     : https://leetcode.com/problems/binary-tree-maximum-path-sum/submissions/2060757218/
// Language: cpp
// Date    : 7/8/2026, 9:59:20 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n)
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
    int solve(TreeNode* node,int &maxi){
        if(!node) return 0;

        int left=max(0,solve(node->left,maxi));
        int ryt=max(0,solve(node->right,maxi));

        maxi=max(maxi,node->val+left+ryt);

        return node->val+max(left,ryt);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        solve(root,maxi);
        return maxi;
    }
};

//T.C = O(n)
//S.C = O(h)