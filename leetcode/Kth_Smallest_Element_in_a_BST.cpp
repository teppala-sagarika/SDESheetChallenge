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
int ans = -1;
    void inorder(TreeNode* root,int &c,int k){
        if(!root || ans!=-1) return ;
        inorder(root->left,c,k);
        c++;
        if(c==k){
            ans=root->val;
            return;
        }
        inorder(root->right,c,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int c=0;
        inorder(root,c,k);
        return ans;
    }
};

//T.C = O(n)
//S.C = O(h)
