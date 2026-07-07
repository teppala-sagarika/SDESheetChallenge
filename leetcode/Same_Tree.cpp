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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true; //both null
        if(!p || !q) return false; //1 miss 
        if(p && q && p->val == q->val){ //check others 
             return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        }
        return false;
    }
};

//T.C = O(n)
//S.C = O(h)
