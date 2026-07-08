// ────────────────────────────────────────────────────────────
// Problem : Construct Binary Tree from Inorder and Postorder Traversal
// Platform: LeetCode
// URL     : https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
// Language: cpp
// Date    : 7/8/2026, 10:56:37 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n)
// Space Complexity: O(n)
// ────────────────────────────────────────────────────────────

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* build(vector<int>& inorder, int is, int ie,
                    vector<int>& postorder, int ps, int pe,
                    unordered_map<int, int>& mp) {

        if (is > ie || ps > pe) return nullptr;

        TreeNode* root = new TreeNode(postorder[pe]);

        int iRoot = mp[root->val];
        int left = iRoot - is;

        root->left = build(inorder, is, iRoot - 1,
                           postorder, ps, ps + left - 1, mp);

        root->right = build(inorder, iRoot + 1, ie,
                            postorder, ps + left, pe - 1, mp);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        unordered_map<int, int> mp;

        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        return build(inorder, 0, inorder.size() - 1,
                     postorder, 0, postorder.size() - 1, mp);
    }
};