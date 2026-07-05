// ────────────────────────────────────────────────────────────
// Problem : Binary Tree Inorder Traversal
// Platform: LeetCode
// URL     : https://leetcode.com/problems/binary-tree-inorder-traversal/submissions/2056843396/
// Language: cpp
// Date    : 7/5/2026, 4:56:03 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n)
// Space Complexity: O(h)
// Notes           : h=height of tree = n , if balanced = log n
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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==nullptr){
            return {};
        }
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* node=root;
        while(true){
            if(node){
                st.push(node);
                node=node->left;
            }else{
                if(st.empty()){
                    break;
                }else{
                    node=st.top();
                    st.pop();
                    ans.push_back(node->val);
                    node=node->right;
                }
            }
        }
        return ans;
    }
};