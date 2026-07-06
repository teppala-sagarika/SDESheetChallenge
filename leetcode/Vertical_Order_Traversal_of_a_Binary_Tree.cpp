// ────────────────────────────────────────────────────────────
// Problem : Vertical Order Traversal of a Binary Tree
// Platform: LeetCode
// URL     : https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/submissions/2058108829/
// Language: cpp
// Date    : 7/6/2026, 7:24:55 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(N log N)
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp;//vertical lvl multinodes
        queue<pair<TreeNode*,pair<int,int>>> q;// node vertical lvl
        q.push({root,{0,0}});
        while(!q.empty()){
            TreeNode* node=q.front().first;
            int ver = q.front().second.first;
            int lvl = q.front().second.second;
            q.pop();
            mp[ver][lvl].insert(node->val);
            if(node->left){
                q.push({node->left,{ver-1,lvl+1}});
            }
            if(node->right){
                q.push({node->right,{ver+1,lvl+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto &pp:mp){
            vector<int> v;
            for(auto &p:pp.second){
                multiset<int> st=p.second;
                for(auto& x:st){
                    v.push_back(x);
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};