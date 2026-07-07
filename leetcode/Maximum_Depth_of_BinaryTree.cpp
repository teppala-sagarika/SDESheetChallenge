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
    void solve(TreeNode* root,int len,int &maxi){
        if(root->left==nullptr || root->right==nullptr){
            maxi=max(maxi,len);
        }
        if(root->left){
            solve(root->left,len+1,maxi);
        }
        if(root->right){
            solve(root->right,len+1,maxi);
        }
    }
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        int maxi=1;
        solve(root,1,maxi);
        return maxi;
    }
};

//T.C = O(n)
//S.C = O(h)
