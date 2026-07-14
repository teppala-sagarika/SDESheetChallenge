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
class BSTIterator{
public:
//constructor
BSTIterator(TreeNode* root,bool flag){
    this->flag=flag;
    pushAll(root);
}
bool hasNxt(){
    return !st.empty();
}
int next(){
    TreeNode* node=st.top();
    st.pop();
    if(flag){//before
        pushAll(node->left);
    }else{//nxt
        pushAll(node->right);
    }
    return node->val;
}
private:
//IF FLAG IS
//true = before
//false = next
stack<TreeNode*> st;
bool flag;

void pushAll(TreeNode* root){
    while(root){
        st.push(root);
        if(!flag){
            //nxt
            root=root->left;
        }else{
            //before
            root=root->right;
        }
    }
}
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root){
            return false;
        }
        BSTIterator l(root,false);//nxt (small)
        BSTIterator r(root,true);//before (large)
        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j==k){
                return true;
            }else if(i+j<k){
                i=l.next();
            }else{
                j=r.next();
            }
        }
        return false;
    }
};

//T.C = O(n)
//S.C = O(n)
