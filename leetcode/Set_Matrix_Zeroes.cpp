// ────────────────────────────────────────────────────────────
// Problem : Set Matrix Zeroes
// Platform: LeetCode
// URL     : https://leetcode.com/problems/set-matrix-zeroes/submissions/2018731252/
// Language: cpp
// Date    : 6/1/2026, 10:59:30 AM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(mn)
// Space Complexity: O(m+n)
// Notes           : arrays
// ────────────────────────────────────────────────────────────

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> row,col;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        bool r=false,c=false;
        for(int i=0;i<m;i++){
            if(row.find(i)!=row.end()) r=true;
            for(int j=0;j<n;j++){
                if(col.find(j)!=col.end()) c=true;
                if(r||c) matrix[i][j]=0;
                c=false;
            }
            r=false;
        }
    }
};