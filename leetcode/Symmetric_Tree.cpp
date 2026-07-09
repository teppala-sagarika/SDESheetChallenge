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
    bool checkSym(TreeNode* root1,TreeNode* root2){
        if(root1==nullptr || root2==nullptr){
            return root1==root2; //both must b null to be symmetric
        }
        return root1->val==root2->val && checkSym(root1->left,root2->right) && checkSym(root1->right,root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return checkSym(root->left,root->right);
    }
};

//T.C = O(n)
//S.C = O(h)
