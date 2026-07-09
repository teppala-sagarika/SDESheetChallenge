/* class TreeNode {
       int val;
       TreeNode *left, *right;
       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   };
*/

class Solution {
public:
    bool checkChildrenSum(TreeNode* root) {
        // Your code goes here
        if(!root || root->left==nullptr && root->right==nullptr) return true;
        
        int left=(root->left)?root->left->val:0;
        int ryt=(root->right)?root->right->val:0;

        if(root->val!=left+ryt) return false;
        return checkChildrenSum(root->left) && checkChildrenSum(root->right);
    }
};

//T.C = O(n)
//S.C = O(h)
