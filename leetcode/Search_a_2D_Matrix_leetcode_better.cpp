class Solution {
public:
    bool binarySearch(vector<int>& row,int l,int h,int k){
        while(l<=h){
            int m=(l+h)/2;
            if(row[m]==k){
                return true;
            }
            else if(row[m]<k){
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            if(binarySearch(matrix[i],0,m-1,target)){
                return true;
            }
        }
        return false;
    }
};

//T.C = O(n log m)
//S.C = O(1)
