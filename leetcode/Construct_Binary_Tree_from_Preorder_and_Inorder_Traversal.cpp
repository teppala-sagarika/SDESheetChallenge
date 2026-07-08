// ────────────────────────────────────────────────────────────
// Problem : Construct Binary Tree from Preorder and Inorder Traversal
// Platform: LeetCode
// URL     : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
// Language: cpp
// Date    : 7/8/2026, 10:52:19 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(N log N)
// Space Complexity: O(N)
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root=build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }
    TreeNode* build(vector<int>& preorder,int ps,int pe, vector<int>& inorder,int is,int ie, map<int,int> &mp){
        if(ps>pe || is>ie) return nullptr;
        TreeNode* root= new TreeNode(preorder[ps]);
        int iRoot=mp[root->val];
        int left=iRoot-is;
        root->left=build(preorder,ps+1,ps+left,inorder,is,iRoot-1,mp);
        root->right=build(preorder,ps+left+1,pe,inorder,iRoot+1,ie,mp);
        return root;
    }
};

