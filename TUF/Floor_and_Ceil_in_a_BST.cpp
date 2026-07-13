/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{	
	public:
		vector<int> floorCeilOfBST(TreeNode* root,int key){
			//your code goes here
            int f=-1;
            int c=-1;
            while(root){
            if(root->data==key){
                f=key;
                c=key;
                break;
            }
            else if(root->data<key){
                f=root->data;
                root=root->right;
            }else{
                c=root->data;
                root=root->left;
            }
            }
            return {f,c};
		}
};

//T.C = O(h)
//S.C = O(1)
