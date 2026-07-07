/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
public:
    bool isLeaf(TreeNode* node) {
    return node->left == nullptr && node->right == nullptr;
    }
    void addLeftBound(TreeNode* root,vector<int>& res){
        TreeNode* cur=root->left;
        while(cur){
            if(!isLeaf(cur)){
                res.push_back(cur->data);
            }
            if(cur->left){
                cur=cur->left;
            }
            else{
                cur=cur->right;
            }
        }
    }
    void addLeaves(TreeNode* root,vector<int>& res){
        if(isLeaf(root)){
            res.push_back(root->data);
            return;
        }
        if(root->left){
            addLeaves(root->left,res);
        }
        if(root->right){
            addLeaves(root->right,res);
        }
    }
    void addRytBound(TreeNode* root,vector<int>& res){
        TreeNode* cur=root->right;
        vector<int> temp;
        while(cur){
            if(!isLeaf(cur)){
                temp.push_back(cur->data);
            }
            if(cur->right){
                cur=cur->right;
            }
            else{
                cur=cur->left;
            }
        }
        for(int i=temp.size()-1;i>=0;i--){
            res.push_back(temp[i]);
        }
    }
    vector <int> boundary(TreeNode* root){
    	//left boundary without leaf nodes
        //leaf nodes
        //right boundary in reverse excluding leaf nodes

        vector<int> res;
        if(!root){
            return res;
        }
        if(!isLeaf(root)) res.push_back(root->data);//root is not leaf?
        addLeftBound(root,res);
        addLeaves(root,res);
        addRytBound(root,res);
        return res;
    }
};

//T.C = O(n)
//S.C = O(h)
