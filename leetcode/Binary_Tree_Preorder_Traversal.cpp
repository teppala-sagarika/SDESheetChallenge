// ────────────────────────────────────────────────────────────
// Problem : Binary Tree Preorder Traversal
// Platform: LeetCode
// URL     : https://leetcode.com/problems/binary-tree-preorder-traversal/
// Language: cpp
// Date    : 7/5/2026, 6:11:38 PM
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* node=root;
        while(true){
            if(node){
                ans.push_back(node->val);
                st.push(node);
                node=node->left;
            }else{
                if(st.empty()){
                    break;
                }else{
                    node=st.top();
                    st.pop();
                    node=node->right;
                }
            }
        }
        return ans;
    }
};
//T.C = O(n)
//S.C = O(h)