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
    void solve(TreeNode* node,int lvl,vector<int> &view){
        if(node==nullptr) return;
        if(lvl==view.size()){
            view.push_back(node->val);
        }
        solve(node->right,lvl+1,view);
        solve(node->left,lvl+1,view);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;
        solve(root,0,view); //node,lvl,ans
        return view;
    }
};
