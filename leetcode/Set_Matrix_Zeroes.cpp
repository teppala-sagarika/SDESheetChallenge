// ────────────────────────────────────────────────────────────
// Problem : Set Matrix Zeroes
// Platform: LeetCode
// URL     : https://leetcode.com/problems/set-matrix-zeroes/submissions/2018765207/
// Language: cpp
// Date    : 6/1/2026, 11:34:40 AM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(nm)
// Space Complexity: O(1)
// Notes           : Arrays ( optimized solution )
// ────────────────────────────────────────────────────────────

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        //matrix[0][..] = col
        //matrix[..][0] = row
        int col0=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    //mark ith row
                    matrix[i][0]=0; 
                    //mark jth col
                    if(j!=0)
                    matrix[0][j]=0;
                    else
                    col0=0;
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]!=0){
                    if(matrix[i][0]==0||matrix[0][j]==0){
                        matrix[i][j]=0;
                    }
                }
            }
        }
        if(matrix[0][0]==0){
            for(int j=0;j<m;j++){
                matrix[0][j]=0;
            }
        }
        if(col0==0){
            for(int i=0;i<n;i++){
                matrix[i][0]=0;
            }
        }
    }
};