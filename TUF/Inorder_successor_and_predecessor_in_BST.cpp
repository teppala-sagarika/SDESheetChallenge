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
		vector<int> succPredBST(TreeNode* root,int key){
			//your code goes here
            int pre=-1;
            int suc=-1;
            TreeNode* node=root;
            while(node!=nullptr){
                if(node->data<=key){
                    node=node->right;
                }
                else{
                    suc=node->data;
                    node=node->left;
                }
            }
            node=root;
            while(node!=nullptr){
                if(node->data>=key){
                    node=node->left;
                }
                else{
                    pre=node->data;
                    node=node->right;
                }
            }
            return {pre,suc};
		}
};

//T.C = O(h)
//S.C = O(1)
