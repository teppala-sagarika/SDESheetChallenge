// ────────────────────────────────────────────────────────────
// Problem : Convert Sorted Array to Binary Search Tree
// Platform: LeetCode
// URL     : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// Language: cpp
// Date    : 7/12/2026, 11:54:31 AM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n)
// Space Complexity: O(log n)
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
    TreeNode* build(int l,int h,vector<int>& nums){
        if(l>h){
            return nullptr;
        }
        int m=l+(h-l)/2;
        TreeNode* root=new TreeNode(nums[m]);
        root->left=build(l,m-1,nums);
        root->right=build(m+1,h,nums);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return build(0,n-1,nums);
    }
};