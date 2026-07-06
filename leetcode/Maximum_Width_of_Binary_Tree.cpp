// ────────────────────────────────────────────────────────────
// Problem : Maximum Width of Binary Tree
// Platform: LeetCode
// URL     : https://leetcode.com/problems/maximum-width-of-binary-tree/submissions/2058237766/
// Language: cpp
// Date    : 7/6/2026, 9:20:36 PM
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        long long ans=0;
        queue<pair<TreeNode*,long long>> q; //node idx
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            long long mini=q.front().second;
            long long first,last;
            for(int i=0;i<n;i++){
                long long curidx=q.front().second-mini;
                TreeNode* node = q.front().first;
                q.pop();
                if(i==0) first=curidx;
                if(i==n-1) last=curidx;
                if(node->left){
                    q.push({node->left,2*curidx+1});
                }
                if(node->right){
                    q.push({node->right,2*curidx+2});
                }
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};