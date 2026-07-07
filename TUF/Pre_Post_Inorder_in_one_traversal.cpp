class Solution {
public:
    void traverse(TreeNode* root, vector<int>& pre,
                  vector<int>& in, vector<int>& post) {

        if (root == NULL)
            return;

        // Preorder
        pre.push_back(root->val);

        traverse(root->left, pre, in, post);

        // Inorder
        in.push_back(root->val);

        traverse(root->right, pre, in, post);

        // Postorder
        post.push_back(root->val);
    }

    vector<vector<int>> treeTraversal(TreeNode* root) {

        vector<int> pre, in, post;

        traverse(root, pre, in, post);

        return {in, pre, post};
    }
};

//T.C = O(N)
//S.C = O(H)
