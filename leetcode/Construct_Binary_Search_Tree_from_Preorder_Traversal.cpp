// ────────────────────────────────────────────────────────────
// Problem : Construct Binary Search Tree from Preorder Traversal
// Platform: LeetCode
// URL     : https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
// Language: cpp
// Date    : 7/12/2026, 10:03:32 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n log n)+O(n)
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
    TreeNode* build(vector<int> &pre,int l,int h,unordered_map<int,int> &mp,int &preidx){
        if(l>h){
            return nullptr;
        }
        int val=pre[preidx];
        preidx++;
        int idx=mp[val];
        TreeNode* root=new TreeNode(val);
        root->left=build(pre,l,idx-1,mp,preidx);
        root->right=build(pre,idx+1,h,mp,preidx);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder=preorder;
        sort(inorder.begin(),inorder.end());
        int n=inorder.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        int pre=0;
        return build(preorder,0,n-1,mp,pre);
    }
};