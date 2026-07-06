// ────────────────────────────────────────────────────────────
// Problem : Binary Tree Level Order Traversal
// Platform: LeetCode
// URL     : https://leetcode.com/problems/binary-tree-level-order-traversal/submissions/2058373065/
// Language: cpp
// Date    : 7/6/2026, 11:04:45 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(N)
// Space Complexity: O(N)
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root){
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;   
        while(!q.empty()){  
            vector<int> lvl;
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                lvl.push_back(node->val);
                if(node->left){
                q.push(node->left);
                }
                if(node->right){
                q.push(node->right);
                }
            }
            ans.push_back(lvl);
        }
        return ans;
    }
};