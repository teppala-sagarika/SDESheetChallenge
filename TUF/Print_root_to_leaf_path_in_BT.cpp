class Solution {
public:

    void dfs(TreeNode* root, vector<int>& path,
             vector<vector<int>>& ans) {

        if (root == NULL)
            return;

        // Include current node
        path.push_back(root->val);

        // Leaf node
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(path);
        }
        else {
            dfs(root->left, path, ans);
            dfs(root->right, path, ans);
        }

        // Backtrack
        path.pop_back();
    }

    vector<vector<int>> rootToLeaf(TreeNode* root) {

        vector<vector<int>> ans;
        vector<int> path;

        dfs(root, path, ans);

        return ans;
    }
};
