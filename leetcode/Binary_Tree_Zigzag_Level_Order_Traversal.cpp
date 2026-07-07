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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};

        bool flag=true;// left to ryt
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty()){
            int n=q.size();
            vector<int> lvl(n);
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                int idx=flag?i:(n-i-1);
                lvl[idx]=node->val;
                if(node->left)
                q.push(node->left);
                if(node->right)
                q.push(node->right);
            }
            flag=!flag;
            ans.push_back(lvl);
        }
        return ans;
    }
};

//T.C = O(n)
//S.C = O(n)
