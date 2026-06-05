// User function template for C++
class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        // your code here
        //start ptr with 1st row last col
        //move ptr left if target is smaller 
        //move ptr down if target is larger
        //stop if out of bound = not found
        int n=mat.size();
        int m=mat[0].size();
        int i=0,j=m-1;
        while(i<n && j>=0){
            if(mat[i][j]==x){
                return true;
            }
            else if(mat[i][j]>x){
                j--;//left
            }
            else{
                i++;//down
            }
        }
        return false;
    }
};
