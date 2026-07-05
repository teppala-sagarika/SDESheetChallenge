// ────────────────────────────────────────────────────────────
// Problem : Binary Tree Postorder Traversal
// Platform: LeetCode
// URL     : https://leetcode.com/problems/binary-tree-postorder-traversal/submissions/2057032413/
// Language: cpp
// Date    : 7/5/2026, 8:30:11 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(2n)
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
    vector<int> postorderTraversal(TreeNode* root) {
        //1 stack
        vector<int> ans;
        TreeNode* cur=root;
        stack<TreeNode*> st;
        while(cur!=nullptr || !st.empty()){
            if(cur!=nullptr){
                st.push(cur);
                cur=cur->left; // go to complete left
            }
            else{
                TreeNode* temp=st.top()->right;
                if(temp==nullptr){
                    temp=st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while(!st.empty() && temp==st.top()->right){
                        //has root?
                        temp=st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
                else{
                    cur=temp;
                }
            }
        }
        return ans;
    }
};
//T.c = O(2n)
//S.C = O(n)