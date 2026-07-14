// ────────────────────────────────────────────────────────────
// Problem : Maximum Sum BST in Binary Tree
// Platform: LeetCode
// URL     : https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/submissions/2067614628/
// Language: cpp
// Date    : 7/14/2026, 10:03:16 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n)
// Space Complexity: O(h)
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
class NodeInfo{
    public:
    bool isBST;
    int mini;
    int maxi;
    int sum;
    NodeInfo(bool isBST,int mini,int maxi,int sum){
        this->isBST=isBST;
        this->mini=mini;
        this->maxi=maxi;
        this->sum=sum;
    }
};
class Solution {
    private:
    int maxsum=0;
    NodeInfo traverse(TreeNode* root){
        if(!root){
            return NodeInfo(true,INT_MAX,INT_MIN,0);
        }
        //post order
        NodeInfo left=traverse(root->left);
        NodeInfo ryt=traverse(root->right);

        if(left.isBST && ryt.isBST && left.maxi< root->val && root->val < ryt.mini){
            int cursum=root->val+left.sum+ryt.sum;
            maxsum=max(maxsum,cursum);
            return NodeInfo(true,min(root->val,left.mini),max(root->val,ryt.maxi),cursum);
        }
        return NodeInfo(false,INT_MAX,INT_MIN,0);
    }
public:
    int maxSumBST(TreeNode* root) {
        maxsum=0;
        traverse(root);
        return maxsum;
    }
};